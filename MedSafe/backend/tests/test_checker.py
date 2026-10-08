from app.checker import check_interactions, excerpts, search_terms, term_pattern
from app.models import Severity
from tests.conftest import label


def test_terms_include_names_classes_and_aliases() -> None:
    terms = search_terms(label("ibuprofen"))
    assert "Ibuprofen" in terms
    assert "Advil" in terms
    assert "Nonsteroidal Anti-inflammatory Drug" in terms
    assert "NSAID" in terms


def test_combination_products_are_split_into_ingredients() -> None:
    terms = search_terms(label("acetaminophen and codeine phosphate"))
    assert "Acetaminophen" in terms
    assert "Codeine" in terms
    assert "Codeine Phosphate" in terms
    assert "opioid" in terms


def test_pattern_matches_plurals_but_not_longer_words() -> None:
    pattern = term_pattern("NSAID")
    assert pattern.search("avoid NSAIDs while taking this")
    assert pattern.search("an nsaid")
    assert not pattern.search("NSAIDXYZ")


def test_pattern_tolerates_hyphen_and_space_differences() -> None:
    assert term_pattern("anti-inflammatory").search("anti inflammatory drugs")


def test_excerpts_return_matching_sentences_only() -> None:
    text = "First sentence. Avoid warfarin here. Another one."
    assert excerpts(text, term_pattern("warfarin")) == ["Avoid warfarin here."]


def test_finds_mentions_in_both_directions() -> None:
    found = check_interactions([label("warfarin sodium"), label("ibuprofen")])
    pairs = {(i.drug_a, i.drug_b, i.matched_term) for i in found}
    assert pairs == {
        ("Ibuprofen", "Warfarin Sodium", "Warfarin"),
        ("Warfarin Sodium", "Ibuprofen", "NSAID"),
    }


def test_salt_forms_are_stripped_from_names() -> None:
    terms = search_terms(label("warfarin sodium"))
    assert terms[:2] == ["Warfarin", "Warfarin Sodium"]


def test_contraindication_via_class_abbreviation_is_high_severity() -> None:
    found = check_interactions(
        [label("sertraline hydrochloride"), label("phenelzine sulfate")]
    )
    assert found[0].drug_a == "Sertraline Hydrochloride"
    assert found[0].drug_b == "Phenelzine Sulfate"
    assert found[0].severity is Severity.HIGH
    assert found[0].section == "Contraindications"
    assert "MAOIs" in found[0].excerpts[0]


def test_results_are_sorted_most_serious_first() -> None:
    found = check_interactions(
        [
            label("ibuprofen"),
            label("sertraline hydrochloride"),
            label("phenelzine sulfate"),
            label("warfarin sodium"),
        ]
    )
    severities = [i.severity for i in found]
    assert severities == sorted(severities, key=lambda s: s is not Severity.HIGH)


def test_unrelated_drugs_have_no_interactions() -> None:
    assert (
        check_interactions([label("acetaminophen"), label("phenelzine sulfate")]) == []
    )
