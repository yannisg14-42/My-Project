#!/usr/bin/env python3


import alchemy

# ---- GLOBALS CONSTANTS
TITLE: str = "=== Distillation 1 ==="
IMPORTING: str = "Using: 'import alchemy' structure to access potions"
TESTING_STRENGTH: str = "Testing strength_potion:"
TESTING_HEAL: str = "Testing heal alias:"


# ---- CODE
def distillation_script_1() -> None:

    print(TITLE)

    print(IMPORTING)

    print(f"{TESTING_STRENGTH} {alchemy.strength_potion()}")

    print(f"{TESTING_HEAL} {alchemy.heal()}")


# ---- IMPORT GUARD
if __name__ == "__main__":

    distillation_script_1()
