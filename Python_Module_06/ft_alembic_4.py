#!/usr/bin/env python3


import alchemy

# ---- Global constants
TITLE: str = "=== Alembic 4 ==="
IMPORTING: str = (
    "Accessing the alchemy module using "
    "'import alchemy'"
)
TESTING: str = "Testing create_air:"
ERROR_TEST: str = (
    "Now show that not all functions can be reached\n"
    "This will raise an exception!\n"
    "Testing the hidden create_earth:"
)


# ---- Code
def alembic_script_4() -> None:

    print(TITLE)

    print(IMPORTING)

    print(f"{TESTING} {alchemy.create_air()}")

    print(ERROR_TEST, end=' ')
    print(alchemy.create_earth())


# ---- Import guard
if __name__ == "__main__":

    alembic_script_4()
