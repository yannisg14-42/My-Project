"""Find places where one drug's FDA label warns about another drug.

The check is text-based: for every pair (A, B) it searches A's label for
B's generic names, brand names and drug classes. A match means the label
*mentions* B in that section; it is a pointer for a pharmacist or doctor,
not a clinical verdict.
"""

import re
from itertools import permutations

from app.models import DrugLabel, Interaction, Severity

# Sections searched, most serious first.
SECTIONS: list[tuple[str, str, Severity]] = [
    ("boxed_warning", "Boxed warning", Severity.HIGH),
    ("contraindications", "Contraindications", Severity.HIGH),
    ("drug_interactions", "Drug interactions", Severity.MODERATE),
    ("warnings", "Warnings", Severity.MODERATE),
]

# Labels usually name drug classes by their common abbreviation.
CLASS_ALIASES: dict[str, list[str]] = {
    "nonsteroidal anti-inflammatory drug": ["NSAID"],
    "selective serotonin reuptake inhibitor": ["SSRI"],
    "serotonin and norepinephrine reuptake inhibitor": ["SNRI"],
    "monoamine oxidase inhibitor": ["MAOI", "MAO inhibitor"],
    "angiotensin converting enzyme inhibitor": ["ACE inhibitor"],
    "angiotensin 2 receptor blocker": ["ARB", "angiotensin receptor blocker"],
    "hmg-coa reductase inhibitor": ["statin"],
    "opioid agonist": ["opioid"],
    "vitamin k antagonist": ["anticoagulant"],
    "anti-coagulant": ["anticoagulant"],
    "platelet aggregation inhibitor": ["antiplatelet"],
}

# Salt forms in official names that labels usually leave out:
# "Warfarin Sodium" is called "warfarin" in other drugs' labels.
SALT_SUFFIX = re.compile(
    r"\s+(sodium|potassium|calcium|magnesium|hydrochloride|hcl|hydrobromide|"
    r"sulfate|phosphate|citrate|maleate|mesylate|besylate|tartrate|succinate|"
    r"fumarate|acetate|bromide|chloride)$",
    re.IGNORECASE,
)

MIN_TERM_LENGTH = 4
MAX_EXCERPTS = 2
MAX_EXCERPT_CHARS = 320
_SENTENCE_SPLIT = re.compile(r"(?<=[.!?;])\s+|\n+")


def search_terms(label: DrugLabel) -> list[str]:
    """Names under which other labels may refer to this drug."""
    terms: list[str] = []
    for name in label.generic_names:
        # Combination products: "Acetaminophen And Codeine Phosphate".
        for ingredient in re.split(r",| and ", name, flags=re.IGNORECASE):
            ingredient = ingredient.strip()
            terms.append(SALT_SUFFIX.sub("", ingredient))
            terms.append(ingredient)
    terms.extend(label.brand_names)
    for pharm_class in label.pharm_classes:
        terms.append(pharm_class)
        terms.extend(CLASS_ALIASES.get(pharm_class.lower(), []))
    unique: dict[str, str] = {}
    for term in terms:
        term = term.strip()
        if len(term) >= MIN_TERM_LENGTH or term.isupper():
            unique.setdefault(term.lower(), term)
    return list(unique.values())


def term_pattern(term: str) -> re.Pattern[str]:
    # Tolerate plurals ("NSAIDs") and space/hyphen differences.
    parts = [re.escape(p) for p in re.split(r"[\s-]+", term) if p]
    body = r"[\s-]+".join(parts)
    return re.compile(rf"(?<![\w-]){body}(?:s|es)?(?![\w-])", re.IGNORECASE)


def excerpts(text: str, pattern: re.Pattern[str]) -> list[str]:
    found: list[str] = []
    for sentence in _SENTENCE_SPLIT.split(text):
        sentence = " ".join(sentence.split())
        match = pattern.search(sentence)
        if not match:
            continue
        if len(sentence) > MAX_EXCERPT_CHARS:
            start = max(0, match.start() - MAX_EXCERPT_CHARS // 2)
            sentence = "…" + sentence[start : start + MAX_EXCERPT_CHARS] + "…"
        found.append(sentence)
        if len(found) == MAX_EXCERPTS:
            break
    return found


def find_mention(source: DrugLabel, target: DrugLabel) -> Interaction | None:
    """The most serious section of `source`'s label that mentions `target`."""
    patterns = [(t, term_pattern(t)) for t in search_terms(target)]
    for field, section_name, severity in SECTIONS:
        text: str | None = getattr(source, field)
        if not text:
            continue
        for term, pattern in patterns:
            quotes = excerpts(text, pattern)
            if quotes:
                return Interaction(
                    drug_a=source.display_name,
                    drug_b=target.display_name,
                    matched_term=term,
                    section=section_name,
                    severity=severity,
                    excerpts=quotes,
                )
    return None


def check_interactions(labels: list[DrugLabel]) -> list[Interaction]:
    found = [
        hit
        for source, target in permutations(labels, 2)
        if (hit := find_mention(source, target)) is not None
    ]
    order = {Severity.HIGH: 0, Severity.MODERATE: 1}
    return sorted(found, key=lambda i: order[i.severity])
