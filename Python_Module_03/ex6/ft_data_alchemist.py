#!/usr/bin/env python3


import random

# ---- Global constants
HEADER: str = "=== Game Data Alchemist ==="
PLAYERS: list[str] = [
        "Himari", "haruto", "Sora", "Ayaka", "akari", "yuki", "Yoshimi"
]
INITIAL_LIST: str = "Initial list of players:"
ALL_CAPITALIZED: str = "New list with all names capitalized:"
INITIALY_CAPITALIZED: str = "New list of capitalized names only:"


# ---- Code
def main() -> None:
    """
    """

    print(HEADER)

    print(f"{INITIAL_LIST} {PLAYERS}")

    all_capitalized: list[str] = [name.capitalize() for name in PLAYERS]

    print(f"{ALL_CAPITALIZED} {all_capitalized}")

    initialy_capitalized: list[str] = [name for name in PLAYERS if name[0].isupper() == True]

    print(f"{INITIALY_CAPITALIZED} {initialy_capitalized}")


# ---- Run the code
if __name__ == "__main__":
    # This line runs the block of code if we call the program DIRECTLY,
    # but will not do so, if we importing it.

    main()
