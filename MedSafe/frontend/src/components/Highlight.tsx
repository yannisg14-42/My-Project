function escapeRegExp(text: string) {
  return text.replace(/[.*+?^${}()|[\]\\]/g, '\\$&')
}

/** Renders `text` with every occurrence of `term` (and its plural) marked. */
export function Highlight({ text, term }: { text: string; term: string }) {
  const body = term.split(/[\s-]+/).filter(Boolean).map(escapeRegExp).join('[\\s-]+')
  const pattern = new RegExp(`(${body}(?:s|es)?)`, 'gi')
  const parts = text.split(pattern)
  return (
    <>
      {parts.map((part, i) => (i % 2 === 1 ? <mark key={i}>{part}</mark> : part))}
    </>
  )
}
