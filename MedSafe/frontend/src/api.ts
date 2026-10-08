import type { CheckResponse } from './types'

export class ApiError extends Error {}

interface ValidationIssue {
  msg: string
}

function describe(detail: unknown): string {
  if (typeof detail === 'string') return detail
  if (Array.isArray(detail) && detail.length > 0) {
    // FastAPI validation errors: "Value error, enter at least two ..."
    return (detail as ValidationIssue[])
      .map((issue) => issue.msg.replace(/^Value error, /, ''))
      .join('; ')
  }
  return 'Something went wrong. Please try again.'
}

export async function checkDrugs(drugs: string[]): Promise<CheckResponse> {
  let response: Response
  try {
    response = await fetch('/api/check', {
      method: 'POST',
      headers: { 'Content-Type': 'application/json' },
      body: JSON.stringify({ drugs }),
    })
  } catch {
    throw new ApiError('Could not reach the MedSafe server.')
  }
  if (!response.ok) {
    const body = (await response.json().catch(() => ({}))) as { detail?: unknown }
    if (response.status === 502) {
      throw new ApiError('The FDA label service is unavailable right now. Please try again shortly.')
    }
    throw new ApiError(describe(body.detail))
  }
  return (await response.json()) as CheckResponse
}
