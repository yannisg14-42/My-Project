#!/usr/bin/env python3


import alchemy.elements

# ---- Global constants
TITLE: str = "=== Alembic 2 ==="
IMPORTING: str = "Accessing alchemy/elements.py using 'import ...' structure"
TESTING: str = "Testing create_earth:"


# ---- Code
def alembic_script_2() -> None:

    print(TITLE)

    print(IMPORTING)

    print(f"{TESTING} {alchemy.elements.create_earth()}")


# ---- Import guard
if __name__ == "__main__":

    alembic_script_2()
