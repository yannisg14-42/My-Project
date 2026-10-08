import re
from typing import Any

import httpx

from app.cache import TTLCache
from app.models import DrugLabel

LABEL_ENDPOINT = "/drug/label.json"
# openFDA query syntax treats quotes and colons specially, so names are
# restricted to characters that appear in real drug names.
_UNSAFE_CHARS = re.compile(r"[^a-z0-9 \-/.,']")


class OpenFDAError(Exception):
    """openFDA could not be reached or returned an unexpected response."""


def normalize_name(name: str) -> str:
    return _UNSAFE_CHARS.sub("", " ".join(name.lower().split())).strip()


def _join(field: Any) -> str | None:
    """openFDA stores label sections as lists of strings."""
    if not field:
        return None
    if isinstance(field, list):
        text = "\n".join(str(part) for part in field if part)
    else:
        text = str(field)
    return text.strip() or None


def _strip_class_suffix(pharm_class: str) -> str:
    # "Nonsteroidal Anti-inflammatory Drug [EPC]" -> "Nonsteroidal ..."
    return re.sub(r"\s*\[[A-Z]+\]$", "", pharm_class).strip()


def parse_label(query: str, raw: dict[str, Any]) -> DrugLabel:
    meta: dict[str, Any] = raw.get("openfda") or {}
    generic = [str(n).title() for n in meta.get("generic_name", [])]
    brand = [str(n).title() for n in meta.get("brand_name", [])]
    classes = [
        _strip_class_suffix(str(c))
        for c in meta.get("pharm_class_epc", []) + meta.get("pharm_class_cs", [])
    ]
    warnings = _join(raw.get("warnings_and_cautions")) or _join(raw.get("warnings"))
    return DrugLabel(
        query=query,
        display_name=generic[0] if generic else (brand[0] if brand else query),
        generic_names=generic,
        brand_names=brand,
        pharm_classes=list(dict.fromkeys(classes)),
        boxed_warning=_join(raw.get("boxed_warning")),
        contraindications=_join(raw.get("contraindications")),
        drug_interactions=_join(raw.get("drug_interactions")),
        warnings=warnings,
        label_id=raw.get("id"),
    )


class OpenFDAClient:
    """Looks up FDA drug labels, caching results (including misses)."""

    def __init__(
        self,
        http: httpx.AsyncClient,
        api_key: str | None = None,
        cache_ttl_seconds: float = 3600,
    ) -> None:
        self._http = http
        self._api_key = api_key
        self._cache: TTLCache[DrugLabel | None] = TTLCache(cache_ttl_seconds)

    async def get_label(self, name: str) -> DrugLabel | None:
        """Return the label for a brand or generic name, or None if unknown."""
        term = normalize_name(name)
        if not term:
            return None
        try:
            return self._cache[term]
        except KeyError:
            pass

        # A space between clauses means OR in openFDA's query language.
        # Labels that list interactions are preferred when several match.
        search = (
            f'(openfda.generic_name:"{term}" openfda.brand_name:"{term}")'
            " AND _exists_:drug_interactions"
        )
        raw = await self._search(search) or await self._search(
            f'openfda.generic_name:"{term}" openfda.brand_name:"{term}"'
        )
        label = parse_label(name, raw) if raw else None
        self._cache.set(term, label)
        return label

    async def _search(self, search: str) -> dict[str, Any] | None:
        params = {"search": search, "limit": "1"}
        if self._api_key:
            params["api_key"] = self._api_key
        try:
            response = await self._http.get(LABEL_ENDPOINT, params=params)
        except httpx.HTTPError as exc:
            raise OpenFDAError(f"could not reach openFDA: {exc}") from exc
        if response.status_code == 404:  # openFDA's "no matches"
            return None
        if response.status_code != 200:
            raise OpenFDAError(f"openFDA answered HTTP {response.status_code}")
        results = response.json().get("results") or []
        return results[0] if results else None
