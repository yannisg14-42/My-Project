#!/usr/bin/env python3


import random

# ---- Global constants
HEADER: str = "=== Game Data Alchemist ==="
PLAYERS: list[str] = [
        "Himari", "haruto", "Sora", "Ayaka", "akari", "yuki", "Yoshimi",
        "SETSUNA"
]
INITIAL_LIST: str = "Initial list of players:"
CAPITALIZE_ALL: str = "New list with all names capitalized:"
INITIALLY_CAPITALIZED: str = "New list of capitalized names only:"


# ---- Code
def main() -> None:
    """
    The main that will handle all the tests.

    It uses list comprehension to create a list of only capitalized str,
    and afterward, also using list comprehension, we create a list only with
    str that were capitalized in the initial list at module level.
    Then we now use dictionary comprehension, to create a dict from, the list
    with only capitalized str, using the str as keys and random int as values.
    And finally we will use those random int to get the average score, and
    create a dict with scores higher than the average with their respective
    keys, using dict comprehension.
    """

    print(HEADER)
    print()
    print(f"{INITIAL_LIST} {PLAYERS}")

    capitalize_all: list[str] = [name.capitalize() for name in PLAYERS]

    print(f"{CAPITALIZE_ALL} {capitalize_all}")

    initially_capitalized: list[str] = [
            name for name in PLAYERS if name == name.capitalize()
    ]

    print(f"{INITIALLY_CAPITALIZED} {initially_capitalized}")
    print()
    score_dict: dict[str, int] = {
            name: random.randint(0, 1000) for name in capitalize_all
    }

    print(f"Score dict: {score_dict}")

    all_scores: list[int] = list(score_dict.values())

    score_average: float = round(sum(all_scores) / len(all_scores), 2)

    print(f"Score average is {score_average}")

    high_scores: dict[str, int] = {
            name: score_dict[name] for name in score_dict
            if score_dict[name] > score_average
    }

    print(f"High scores: {high_scores}")


# ---- Run the code
if __name__ == "__main__":
    # This line runs the block of code if we call the program DIRECTLY,
    # but will not do so, if we importing it.

    main()
