#!/usr/bin/env python3


from alchemy import create_air

# ---- Global constants
TITLE: str = "=== Alembic 5 ==="
IMPORTING: str = (
    "Accessing the alchemy module using "
    "'from alchemy import ...'"
)
TESTING: str = "Testing create_air:"


# ---- Code
def alembic_script_5() -> None:

    print(TITLE)

    print(IMPORTING)

    print(f"{TESTING} {create_air()}")


# ---- Import guard
if __name__ == "__main__":

    alembic_script_5()
