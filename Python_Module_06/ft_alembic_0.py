#!/usr/bin/env python3


import elements

# ---- Global constant
TITLE: str = "=== Alembic 0 ==="
IMPORTING: str = "Using: 'import ...' structure to access elements.py"
TESTING: str = "Testing create_fire:"


# ---- Code
def alembic_script_0() -> None:

    print(TITLE)

    print(IMPORTING)

    print(f"{TESTING} {elements.create_fire()}")


# ---- Import guard
if __name__ == "__main__":

    alembic_script_0()
