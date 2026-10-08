import { render, screen } from '@testing-library/react'
import userEvent from '@testing-library/user-event'
import { afterEach, describe, expect, it, vi } from 'vitest'
import App from './App'
import type { CheckResponse } from './types'

const RESPONSE: CheckResponse = {
  drugs: [
    {
      query: 'warfarin',
      display_name: 'Warfarin Sodium',
      generic_names: ['Warfarin Sodium'],
      brand_names: ['Coumadin'],
      pharm_classes: ['Vitamin K Antagonist'],
      boxed_warning: 'WARNING: BLEEDING RISK',
      label_id: 'a',
    },
    {
      query: 'Advil',
      display_name: 'Ibuprofen',
      generic_names: ['Ibuprofen'],
      brand_names: ['Advil'],
      pharm_classes: ['Nonsteroidal Anti-inflammatory Drug'],
      boxed_warning: null,
      label_id: 'b',
    },
  ],
  not_found: ['unicornium'],
  interactions: [
    {
      drug_a: 'Ibuprofen',
      drug_b: 'Warfarin Sodium',
      matched_term: 'Warfarin',
      section: 'Drug interactions',
      severity: 'moderate',
      excerpts: ['Anticoagulants such as warfarin increase bleeding.'],
    },
  ],
  disclaimer: 'Not medical advice.',
}

function mockFetch(status: number, body: unknown) {
  const fetchMock = vi.fn().mockResolvedValue(
    new Response(JSON.stringify(body), {
      status,
      headers: { 'Content-Type': 'application/json' },
    }),
  )
  vi.stubGlobal('fetch', fetchMock)
  return fetchMock
}

afterEach(() => vi.unstubAllGlobals())

async function addDrugs(...names: string[]) {
  const input = screen.getByLabelText('Your medicines')
  for (const name of names) await userEvent.type(input, `${name}{Enter}`)
}

describe('App', () => {
  it('needs two medicines before checking', async () => {
    render(<App />)
    const button = screen.getByRole('button', { name: 'Check interactions' })
    expect(button).toBeDisabled()
    await addDrugs('warfarin')
    expect(button).toBeDisabled()
    await addDrugs('Advil')
    expect(button).toBeEnabled()
  })

  it('ignores duplicates and lets you remove a medicine', async () => {
    render(<App />)
    await addDrugs('warfarin', 'WARFARIN', 'Advil')
    expect(screen.getAllByRole('listitem')).toHaveLength(2)
    await userEvent.click(screen.getByRole('button', { name: 'Remove Advil' }))
    expect(screen.getAllByRole('listitem')).toHaveLength(1)
  })

  it('shows warnings, unknown drugs and highlights the match', async () => {
    const fetchMock = mockFetch(200, RESPONSE)
    render(<App />)
    await addDrugs('warfarin', 'Advil', 'unicornium')
    await userEvent.click(screen.getByRole('button', { name: 'Check interactions' }))

    expect(await screen.findByText('1 label warning found')).toBeInTheDocument()
    expect(JSON.parse(fetchMock.mock.calls[0][1].body)).toEqual({
      drugs: ['warfarin', 'Advil', 'unicornium'],
    })
    expect(screen.getByText('warfarin', { selector: 'mark' })).toBeInTheDocument()
    expect(screen.getByRole('alert')).toHaveTextContent('unicornium')
    expect(screen.getByText('FDA boxed warning')).toBeInTheDocument()
  })

  it('explains when the FDA service is down', async () => {
    mockFetch(502, { detail: 'could not reach openFDA' })
    render(<App />)
    await userEvent.click(screen.getByRole('button', { name: 'Warfarin + Ibuprofen' }))
    expect(await screen.findByRole('alert')).toHaveTextContent('FDA label service is unavailable')
  })
})
