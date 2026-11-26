#!/usr/bin/env python3


from alchemy.elements import create_air

# ---- Global constants
TITLE: str = "=== Alembic 3 ==="
IMPORTING: str = (
    "Accessing alchemy/elements.py using "
    "'from ... import ...' structure"
)
TESTING: str = "Testing create_air:"


# ---- Code
def alembic_script_3() -> None:

    print(TITLE)

    print(IMPORTING)

    print(f"{TESTING} {create_air()}")


# ---- Import guard
if __name__ == "__main__":

    alembic_script_3()
