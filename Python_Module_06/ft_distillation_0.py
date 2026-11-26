#!/usr/bin/env python3


from alchemy.potions import healing_potion, strength_potion

# ---- GLOBALS CONSTANTS
TITLE: str = "=== Distillation 0 ==="
IMPORTING: str = "Direct access to alchemy/potions.py"
TESTING_STRENGTH: str = "Testing strength_potion:"
TESTING_HEAL: str = "Testing healing_potion:"


# ---- CODE
def distillation_script_0() -> None:

    print(TITLE)

    print(IMPORTING)

    print(f"{TESTING_STRENGTH} {strength_potion()}")

    print(f"{TESTING_HEAL} {healing_potion()}")


# ---- IMPORT GUARD
if __name__ == "__main__":

    distillation_script_0()
