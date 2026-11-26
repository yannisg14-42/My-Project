#!/usr/bin/env python3


from elements import create_water

# ---- Global constant
TITLE: str = "=== Alembic 1 ==="
IMPORTING: str = "Using: 'from ... import ...' structure to access elements.py"
TESTING: str = "Testing create_water:"


# ---- Code
def alembic_script_1() -> None:

    print(TITLE)

    print(IMPORTING)

    print(f"{TESTING} {create_water()}")


# ---- Import guard
if __name__ == "__main__":

    alembic_script_1()
