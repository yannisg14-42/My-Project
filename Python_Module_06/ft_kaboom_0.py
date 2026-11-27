#!/usr/bin/env python3


import alchemy.grimoire

# |-- GLOBAL CONSTANTS --|
TITLE: str = "=== Kaboom 0 ==="
IMPORTING: str = "Using grimoire module directly"
TESTING: str = "Testing record light spell:"


# |-- CODE --|
def kaboom_script_0() -> None:

    print(TITLE)

    print(IMPORTING)

    spell_validation: str = (alchemy.grimoire.light_spell_record(
        "Fantasy",
        "Earth, wind and fire"
    )
    )

    print(f"{TESTING} {spell_validation}")


# |-- IMPORT GUARD --|
if __name__ == "__main__":

    kaboom_script_0()
