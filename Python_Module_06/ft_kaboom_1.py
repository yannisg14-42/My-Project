#!/usr/bin/env python3


# |-- GLOBAL CONSTANTS --|
TITLE: str = "=== Kaboom 1 ==="
IMPORTING: str = "Access to alchemy/grimoire/dark_spellbook.py directly"
TESTING: str = "Testing import now - THIS WILL RAISE AN UNCAUGHT EXCEPTION"


# |-- CODE --|
def kaboom_script_1() -> None:

    print(TITLE)

    print(IMPORTING)

    print(TESTING)

    import alchemy.grimoire.dark_spellbook

    spell_validation: str = (alchemy.grimoire.dark_spellbook.dark_spell_record(
        "Fantasy",
        "Earth, wind and fire"
    )
    )

    print(spell_validation)


# |-- IMPORT GUARD --|
if __name__ == "__main__":

    kaboom_script_1()
