#!/usr/bin/env python3


import alchemy.transmutation

# ---- GLOBAL CONSTANTS
TITLE: str = "=== Transmutation 1 ==="
IMPORTING: str = "Import transmutation module directly"
TESTING: str = "Testing lead to gold:"


# ---- CODE
def transmutation_script_1() -> None:

    print(TITLE)

    print(IMPORTING)

    print(f"{TESTING} {alchemy.transmutation.lead_to_gold()}")


# ---- IMPORT GUARD
if __name__ == "__main__":

    transmutation_script_1()
