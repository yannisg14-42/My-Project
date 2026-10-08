// Mirrors the backend's response models (backend/app/models.py).

export type Severity = 'high' | 'moderate'

export interface DrugSummary {
  query: string
  display_name: string
  generic_names: string[]
  brand_names: string[]
  pharm_classes: string[]
  boxed_warning: string | null
  label_id: string | null
}

export interface Interaction {
  drug_a: string
  drug_b: string
  matched_term: string
  section: string
  severity: Severity
  excerpts: string[]
}

export interface CheckResponse {
  drugs: DrugSummary[]
  not_found: string[]
  interactions: Interaction[]
  disclaimer: string
}
