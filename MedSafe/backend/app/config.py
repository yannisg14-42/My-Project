from functools import lru_cache

from pydantic_settings import BaseSettings, SettingsConfigDict


class Settings(BaseSettings):
    """Runtime settings, read from environment variables prefixed MEDSAFE_."""

    model_config = SettingsConfigDict(env_prefix="MEDSAFE_")

    openfda_base_url: str = "https://api.fda.gov"
    # Optional: a free key from open.fda.gov raises the daily request limit.
    openfda_api_key: str | None = None
    request_timeout_seconds: float = 10.0
    cache_ttl_seconds: int = 3600
    cors_origins: list[str] = ["http://localhost:5173"]


@lru_cache
def get_settings() -> Settings:
    return Settings()
