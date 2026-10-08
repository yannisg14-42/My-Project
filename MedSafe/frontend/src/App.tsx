import { useState, type FormEvent } from 'react'
import { ApiError, checkDrugs } from './api'
import { DrugInput } from './components/DrugInput'
import { Results } from './components/Results'
import type { CheckResponse } from './types'

const EXAMPLES = [
  ['Warfarin', 'Ibuprofen'],
  ['Sertraline', 'Phenelzine'],
  ['Simvastatin', 'Clarithromycin', 'Amlodipine'],
]

const DISCLAIMER =
  'MedSafe searches official FDA drug label text. It can miss interactions and is not medical advice. Always ask a pharmacist or doctor before starting, stopping or combining medicines.'

export default function App() {
  const [drugs, setDrugs] = useState<string[]>([])
  const [result, setResult] = useState<CheckResponse | null>(null)
  const [error, setError] = useState<string | null>(null)
  const [loading, setLoading] = useState(false)

  async function run(names: string[]) {
    setLoading(true)
    setError(null)
    try {
      setResult(await checkDrugs(names))
    } catch (e) {
      setResult(null)
      setError(e instanceof ApiError ? e.message : 'Something went wrong. Please try again.')
    } finally {
      setLoading(false)
    }
  }

  function onSubmit(event: FormEvent) {
    event.preventDefault()
    if (drugs.length >= 2) void run(drugs)
  }

  function updateDrugs(next: string[]) {
    setDrugs(next)
    setResult(null)
  }

  return (
    <div className="page">
      <header className="hero">
        <div className="logo" aria-hidden="true">
          +
        </div>
        <div>
          <h1>MedSafe</h1>
          <p>Check whether your medicines warn about each other, straight from official FDA drug labels.</p>
        </div>
      </header>

      <main>
        <form className="card checker" onSubmit={onSubmit}>
          <DrugInput drugs={drugs} onChange={updateDrugs} />
          <div className="actions">
            <button type="submit" className="primary" disabled={drugs.length < 2 || loading}>
              {loading ? 'Checking…' : 'Check interactions'}
            </button>
            {drugs.length === 1 && <span className="hint">Add at least one more medicine.</span>}
          </div>
          <div className="examples">
            <span>Try:</span>
            {EXAMPLES.map((example) => (
              <button
                key={example.join()}
                type="button"
                className="link"
                onClick={() => {
                  setDrugs(example)
                  void run(example)
                }}
              >
                {example.join(' + ')}
              </button>
            ))}
          </div>
        </form>

        {error && (
          <p className="error" role="alert">
            {error}
          </p>
        )}
        {result && <Results result={result} />}
      </main>

      <footer>
        <p>{result?.disclaimer ?? DISCLAIMER}</p>
        <p>
          Data: <a href="https://open.fda.gov/apis/drug/label/">openFDA drug labels</a>. Not
          affiliated with or endorsed by the FDA.
        </p>
      </footer>
    </div>
  )
}
