import { useState, type KeyboardEvent } from 'react'

export const MAX_DRUGS = 10

interface Props {
  drugs: string[]
  onChange: (drugs: string[]) => void
}

export function DrugInput({ drugs, onChange }: Props) {
  const [text, setText] = useState('')

  function add(raw: string) {
    const names = raw
      .split(',')
      .map((n) => n.trim().replace(/\s+/g, ' '))
      .filter(Boolean)
    const next = [...drugs]
    for (const name of names) {
      const isDuplicate = next.some((d) => d.toLowerCase() === name.toLowerCase())
      if (!isDuplicate && next.length < MAX_DRUGS) next.push(name)
    }
    onChange(next)
    setText('')
  }

  function onKeyDown(event: KeyboardEvent<HTMLInputElement>) {
    if ((event.key === 'Enter' || event.key === ',') && text.trim()) {
      event.preventDefault()
      add(text)
    } else if (event.key === 'Backspace' && !text && drugs.length > 0) {
      onChange(drugs.slice(0, -1))
    }
  }

  const full = drugs.length >= MAX_DRUGS

  return (
    <div className="drug-input">
      <label htmlFor="drug-name">Your medicines</label>
      <div className="chip-field">
        <ul className="chips" aria-label="Selected medicines">
          {drugs.map((drug) => (
            <li key={drug} className="chip">
              {drug}
              <button
                type="button"
                aria-label={`Remove ${drug}`}
                onClick={() => onChange(drugs.filter((d) => d !== drug))}
              >
                ×
              </button>
            </li>
          ))}
        </ul>
        <input
          id="drug-name"
          value={text}
          disabled={full}
          placeholder={full ? `Up to ${MAX_DRUGS} medicines` : 'Type a name, press Enter'}
          onChange={(e) => setText(e.target.value)}
          onKeyDown={onKeyDown}
          onBlur={() => text.trim() && add(text)}
          autoComplete="off"
        />
      </div>
      <p className="hint">Brand or generic names both work, e.g. “Advil” or “ibuprofen”.</p>
    </div>
  )
}
