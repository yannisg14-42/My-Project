import json
import re
from collections.abc import Iterator
from pathlib import Path
from typing import Any

import httpx
import pytest
from fastapi.testclient import TestClient

from app.main import app, get_openfda
from app.models import DrugLabel
from app.openfda import OpenFDAClient, parse_label

FIXTURES = Path(__file__).parent / "fixtures" / "labels.json"
RAW_LABELS: list[dict[str, Any]] = json.loads(FIXTURES.read_text())["labels"]


def raw_label(generic_name: str) -> dict[str, Any]:
    for raw in RAW_LABELS:
        if generic_name.upper() in raw["openfda"]["generic_name"]:
            return raw
    raise KeyError(generic_name)


def label(generic_name: str) -> DrugLabel:
    return parse_label(generic_name, raw_label(generic_name))


class FakeOpenFDA:
    """Answers label searches from the fixture file, like api.fda.gov would."""

    def __init__(self) -> None:
        self.requests: list[httpx.Request] = []
        self.fail = False

    def handler(self, request: httpx.Request) -> httpx.Response:
        self.requests.append(request)
        if self.fail:
            return httpx.Response(500)
        search = request.url.params["search"]
        term = re.search(r'"([^"]+)"', search)
        assert term is not None
        needs_interactions = "_exists_:drug_interactions" in search
        for raw in RAW_LABELS:
            names = raw["openfda"]["generic_name"] + raw["openfda"]["brand_name"]
            if term.group(1).upper() not in names:
                continue
            if needs_interactions and "drug_interactions" not in raw:
                continue
            return httpx.Response(200, json={"results": [raw]})
        return httpx.Response(404, json={"error": {"code": "NOT_FOUND"}})


@pytest.fixture
def fake_fda() -> FakeOpenFDA:
    return FakeOpenFDA()


@pytest.fixture
def openfda(fake_fda: FakeOpenFDA) -> OpenFDAClient:
    http = httpx.AsyncClient(
        base_url="https://api.fda.test",
        transport=httpx.MockTransport(fake_fda.handler),
    )
    return OpenFDAClient(http)


@pytest.fixture
def client(openfda: OpenFDAClient) -> Iterator[TestClient]:
    app.dependency_overrides[get_openfda] = lambda: openfda
    yield TestClient(app)
    app.dependency_overrides.clear()
