import asyncio
from collections.abc import AsyncIterator
from contextlib import asynccontextmanager
from typing import Annotated

import httpx
from fastapi import Depends, FastAPI, HTTPException, Request
from fastapi.middleware.cors import CORSMiddleware

from app.checker import check_interactions
from app.config import get_settings
from app.models import CheckRequest, CheckResponse, DrugSummary
from app.openfda import OpenFDAClient, OpenFDAError

DISCLAIMER = (
    "MedSafe searches official FDA drug label text for mentions of your other "
    "medicines. It can miss interactions and is not medical advice. Always ask "
    "a pharmacist or doctor before starting, stopping or combining medicines."
)


@asynccontextmanager
async def lifespan(app: FastAPI) -> AsyncIterator[None]:
    settings = get_settings()
    async with httpx.AsyncClient(
        base_url=settings.openfda_base_url,
        timeout=settings.request_timeout_seconds,
    ) as http:
        app.state.openfda = OpenFDAClient(
            http,
            api_key=settings.openfda_api_key,
            cache_ttl_seconds=settings.cache_ttl_seconds,
        )
        yield


app = FastAPI(
    title="MedSafe API",
    description="Check medicines for label warnings about each other.",
    version="0.1.0",
    lifespan=lifespan,
)
app.add_middleware(
    CORSMiddleware,
    allow_origins=get_settings().cors_origins,
    allow_methods=["GET", "POST"],
    allow_headers=["Content-Type"],
)


def get_openfda(request: Request) -> OpenFDAClient:
    client: OpenFDAClient = request.app.state.openfda
    return client


OpenFDA = Annotated[OpenFDAClient, Depends(get_openfda)]


@app.get("/api/health")
async def health() -> dict[str, str]:
    return {"status": "ok"}


@app.get("/api/drugs/{name}")
async def get_drug(name: str, openfda: OpenFDA) -> DrugSummary:
    try:
        label = await openfda.get_label(name)
    except OpenFDAError as exc:
        raise HTTPException(status_code=502, detail=str(exc)) from exc
    if label is None:
        raise HTTPException(status_code=404, detail=f"No FDA label for '{name}'")
    return DrugSummary.from_label(label)


@app.post("/api/check")
async def check(body: CheckRequest, openfda: OpenFDA) -> CheckResponse:
    try:
        labels = await asyncio.gather(*(openfda.get_label(d) for d in body.drugs))
    except OpenFDAError as exc:
        raise HTTPException(status_code=502, detail=str(exc)) from exc
    found = [label for label in labels if label is not None]
    return CheckResponse(
        drugs=[DrugSummary.from_label(label) for label in found],
        not_found=[d for d, label in zip(body.drugs, labels, strict=True) if not label],
        interactions=check_interactions(found),
        disclaimer=DISCLAIMER,
    )
