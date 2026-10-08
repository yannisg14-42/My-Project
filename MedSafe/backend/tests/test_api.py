from fastapi.testclient import TestClient

from tests.conftest import FakeOpenFDA


def test_health(client: TestClient) -> None:
    assert client.get("/api/health").json() == {"status": "ok"}


def test_get_drug_by_brand_name(client: TestClient) -> None:
    response = client.get("/api/drugs/Advil")
    assert response.status_code == 200
    body = response.json()
    assert body["display_name"] == "Ibuprofen"
    assert body["query"] == "Advil"


def test_get_unknown_drug_is_404(client: TestClient) -> None:
    assert client.get("/api/drugs/notarealdrug").status_code == 404


def test_check_reports_interactions_and_unknown_drugs(client: TestClient) -> None:
    response = client.post(
        "/api/check", json={"drugs": ["warfarin sodium", "Advil", "unicornium"]}
    )
    assert response.status_code == 200
    body = response.json()
    assert [d["display_name"] for d in body["drugs"]] == [
        "Warfarin Sodium",
        "Ibuprofen",
    ]
    assert body["not_found"] == ["unicornium"]
    assert len(body["interactions"]) == 2
    assert "not medical advice" in body["disclaimer"]


def test_check_needs_two_different_drugs(client: TestClient) -> None:
    response = client.post("/api/check", json={"drugs": ["Advil", " advil "]})
    assert response.status_code == 422


def test_check_limits_number_of_drugs(client: TestClient) -> None:
    response = client.post("/api/check", json={"drugs": [f"d{i}" for i in range(11)]})
    assert response.status_code == 422


def test_upstream_failure_is_502(client: TestClient, fake_fda: FakeOpenFDA) -> None:
    fake_fda.fail = True
    response = client.post("/api/check", json={"drugs": ["Advil", "Tylenol"]})
    assert response.status_code == 502


def test_labels_are_cached(client: TestClient, fake_fda: FakeOpenFDA) -> None:
    client.get("/api/drugs/Advil")
    client.get("/api/drugs/advil")
    client.get("/api/drugs/unicornium")
    count = len(fake_fda.requests)
    client.get("/api/drugs/unicornium")
    assert len(fake_fda.requests) == count == 3  # Advil once, miss twice


def test_falls_back_to_labels_without_interaction_section(
    client: TestClient,
) -> None:
    # The acetaminophen fixture has no drug_interactions section.
    response = client.get("/api/drugs/Tylenol")
    assert response.status_code == 200
    assert response.json()["display_name"] == "Acetaminophen"
