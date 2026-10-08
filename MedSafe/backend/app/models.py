from enum import StrEnum

from pydantic import BaseModel, Field, field_validator

MAX_DRUGS = 10


class Severity(StrEnum):
    HIGH = "high"
    MODERATE = "moderate"


class DrugLabel(BaseModel):
    """The parts of an FDA drug label that MedSafe uses."""

    query: str
    display_name: str
    generic_names: list[str]
    brand_names: list[str]
    pharm_classes: list[str]
    boxed_warning: str | None = None
    contraindications: str | None = None
    drug_interactions: str | None = None
    warnings: str | None = None
    label_id: str | None = None


class DrugSummary(BaseModel):
    query: str
    display_name: str
    generic_names: list[str]
    brand_names: list[str]
    pharm_classes: list[str]
    boxed_warning: str | None
    label_id: str | None

    @classmethod
    def from_label(cls, label: DrugLabel) -> "DrugSummary":
        return cls(
            query=label.query,
            display_name=label.display_name,
            generic_names=label.generic_names,
            brand_names=label.brand_names,
            pharm_classes=label.pharm_classes,
            boxed_warning=label.boxed_warning,
            label_id=label.label_id,
        )


class Interaction(BaseModel):
    """One drug's label mentioning another drug (or its drug class)."""

    drug_a: str = Field(description="Drug whose label contains the mention")
    drug_b: str = Field(description="Drug that is mentioned")
    matched_term: str
    section: str
    severity: Severity
    excerpts: list[str]


class CheckRequest(BaseModel):
    drugs: list[str] = Field(min_length=2, max_length=MAX_DRUGS)

    @field_validator("drugs")
    @classmethod
    def clean_names(cls, drugs: list[str]) -> list[str]:
        cleaned: list[str] = []
        for name in drugs:
            name = " ".join(name.split())
            if not name:
                raise ValueError("drug names must not be empty")
            if len(name) > 80:
                raise ValueError("drug names must be at most 80 characters")
            if name.lower() not in (c.lower() for c in cleaned):
                cleaned.append(name)
        if len(cleaned) < 2:
            raise ValueError("enter at least two different drugs")
        return cleaned


class CheckResponse(BaseModel):
    drugs: list[DrugSummary]
    not_found: list[str]
    interactions: list[Interaction]
    disclaimer: str
