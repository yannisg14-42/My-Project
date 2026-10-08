import type { CheckResponse, DrugSummary, Interaction } from '../types'
import { Highlight } from './Highlight'

const SEVERITY_LABEL = { high: 'Serious warning', moderate: 'Caution' } as const

function InteractionCard({ interaction }: { interaction: Interaction }) {
  const { drug_a, drug_b, section, severity, excerpts, matched_term } = interaction
  return (
    <article className={`card interaction ${severity}`}>
      <header>
        <span className={`badge ${severity}`}>{SEVERITY_LABEL[severity]}</span>
        <h3>
          {drug_a} <span className="arrow">→</span> {drug_b}
        </h3>
      </header>
      <p className="meta">
        The <strong>{section.toLowerCase()}</strong> section of {drug_a}’s label mentions{' '}
        <strong>{matched_term}</strong>
        {matched_term.toLowerCase() !== drug_b.toLowerCase() && <> (matches {drug_b})</>}:
      </p>
      {excerpts.map((quote) => (
        <blockquote key={quote}>
          <Highlight text={quote} term={matched_term} />
        </blockquote>
      ))}
    </article>
  )
}

function DrugCard({ drug }: { drug: DrugSummary }) {
  const otherNames = drug.brand_names.filter(
    (n) => n.toLowerCase() !== drug.display_name.toLowerCase(),
  )
  return (
    <article className="card drug">
      <h3>{drug.display_name}</h3>
      {drug.query.toLowerCase() !== drug.display_name.toLowerCase() && (
        <p className="meta">You entered “{drug.query}”</p>
      )}
      {otherNames.length > 0 && <p className="meta">Also sold as {otherNames.join(', ')}</p>}
      {drug.pharm_classes.length > 0 && (
        <ul className="tags">
          {drug.pharm_classes.map((c) => (
            <li key={c}>{c}</li>
          ))}
        </ul>
      )}
      {drug.boxed_warning && (
        <details className="boxed">
          <summary>FDA boxed warning</summary>
          <p>{drug.boxed_warning}</p>
        </details>
      )}
    </article>
  )
}

export function Results({ result }: { result: CheckResponse }) {
  const { interactions, drugs, not_found } = result
  const serious = interactions.filter((i) => i.severity === 'high').length

  return (
    <section className="results" aria-live="polite">
      <div className={`summary ${interactions.length ? (serious ? 'high' : 'moderate') : 'clear'}`}>
        {interactions.length === 0 ? (
          <>
            <h2>No label warnings found between these medicines</h2>
            <p>That does not prove the combination is safe — labels do not list every interaction.</p>
          </>
        ) : (
          <>
            <h2>
              {interactions.length} label warning{interactions.length > 1 ? 's' : ''} found
            </h2>
            <p>
              {serious > 0
                ? `${serious} from a boxed warning or contraindication. Talk to a pharmacist or doctor before combining these.`
                : 'Show these to a pharmacist or doctor before combining these medicines.'}
            </p>
          </>
        )}
      </div>

      {not_found.length > 0 && (
        <p className="not-found" role="alert">
          No FDA label found for: <strong>{not_found.join(', ')}</strong>. Check the spelling or try
          the generic name.
        </p>
      )}

      {interactions.length > 0 && (
        <>
          <h2 className="section-title">Warnings</h2>
          {interactions.map((i) => (
            <InteractionCard key={`${i.drug_a}-${i.drug_b}`} interaction={i} />
          ))}
        </>
      )}

      {drugs.length > 0 && (
        <>
          <h2 className="section-title">Your medicines</h2>
          <div className="drug-grid">
            {drugs.map((d) => (
              <DrugCard key={d.query} drug={d} />
            ))}
          </div>
        </>
      )}
    </section>
  )
}
