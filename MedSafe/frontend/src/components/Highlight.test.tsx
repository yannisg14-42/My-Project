import { render } from '@testing-library/react'
import { expect, it } from 'vitest'
import { Highlight } from './Highlight'

function marks(text: string, term: string) {
  const { container } = render(<Highlight text={text} term={term} />)
  return [...container.querySelectorAll('mark')].map((m) => m.textContent)
}

it('marks plurals case-insensitively', () => {
  expect(marks('Avoid NSAIDs and nsaid use.', 'NSAID')).toEqual(['NSAIDs', 'nsaid'])
})

it('treats regex characters in the term literally', () => {
  expect(marks('Use of HMG-CoA (statins) is fine.', 'HMG-CoA')).toEqual(['HMG-CoA'])
  expect(marks('a.b', '.')).toEqual(['.'])
})
