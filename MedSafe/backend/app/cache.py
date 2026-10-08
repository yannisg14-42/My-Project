import time


class TTLCache[T]:
    """A small in-memory cache whose entries expire after `ttl_seconds`."""

    def __init__(self, ttl_seconds: float, max_entries: int = 1024) -> None:
        self._ttl = ttl_seconds
        self._max_entries = max_entries
        self._data: dict[str, tuple[float, T]] = {}

    def __getitem__(self, key: str) -> T:
        """Return the cached value; raise KeyError if absent or expired."""
        expires_at, value = self._data[key]
        if time.monotonic() >= expires_at:
            del self._data[key]
            raise KeyError(key)
        return value

    def set(self, key: str, value: T) -> None:
        if len(self._data) >= self._max_entries and key not in self._data:
            # Drop the oldest insertion; dicts keep insertion order.
            del self._data[next(iter(self._data))]
        self._data[key] = (time.monotonic() + self._ttl, value)
