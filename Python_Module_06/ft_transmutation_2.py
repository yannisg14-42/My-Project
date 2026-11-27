#!/usr/bin/env python3


import alchemy

# ---- GLOBAL CONSTANTS
TITLE: str = "=== Transmutation 2 ==="
IMPORTING: str = "Import alchemy module only"
TESTING: str = "Testing lead to gold:"


# ---- CODE
def transmutation_script_2() -> None:

    print(TITLE)

    print(IMPORTING)

    print(f"{TESTING} {alchemy.lead_to_gold()}")


# ---- IMPORT GUARD
if __name__ == "__main__":

    transmutation_script_2()
