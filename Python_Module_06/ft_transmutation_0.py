#!/usr/bin/env python3


import alchemy.transmutation.recipes

# ---- GLOBAL CONSTANTS
TITLE: str = "=== Transmutation 0 ==="
IMPORTING: str = "Using file alchemy/transmutation/recipes.py directly"
TESTING: str = "Testing lead to gold:"


# ---- CODE
def transmutation_script_0() -> None:

    print(TITLE)

    print(IMPORTING)

    print(f"{TESTING} {alchemy.transmutation.recipes.lead_to_gold()}")


# ---- IMPORT GUARD
if __name__ == "__main__":

    transmutation_script_0()
