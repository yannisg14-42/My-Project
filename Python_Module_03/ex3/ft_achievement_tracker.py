#!/usr/bin/env python3


import random

# ---- Global Constant
HEADER: str = "=== Achievement Tracker System ==="
DISTINCT: str = "All distincts achievements:"
COMMON: str = "Common achievements:"
MISSING: str = "is missing:"


# ---- Code
def gen_player_achievement() -> set[str]:
    """
    A function
    """

    achievements: list[str] = [
        'Boss Slayer', 'Collector Supreme', 'Crafting Genius',
        'First Steps', 'Master Explorer', 'Sharp Mind', 'Speed Runner',
        'Strategist', 'Survivor', 'Treasure Hunter', 'Unstoppable',
        'Untouchable', 'World Savior'
    ]

    k: int = random.randint(6, 12)

    player_achievement: list[str] = random.sample(achievements, k)

    return set(player_achievement)


# ---- Runs the Code
if __name__ == "__main__":
    # This line runs the block of if we call the program DIRECTLY,
    # but will not, if it is imported.

    print(HEADER)

    set1: set[str] = gen_player_achievement()
    set2: set[str] = gen_player_achievement()
    set3: set[str] = gen_player_achievement()
    set4: set[str] = gen_player_achievement()

    all_achievements: set[str] = set1.union(set2, set3, set4)

    common_achievements: set[str] = set1.intersection(set2, set3, set4)

    unique_achievements1: set[str] = set1.difference(set2, set3, set4)
    unique_achievements2: set[str] = set2.difference(set1, set3, set4)
    unique_achievements3: set[str] = set3.difference(set1, set2, set4)
    unique_achievements4: set[str] = set4.difference(set1, set2, set3)

    print()

    print(f"Player Yukina: {set1}")
    print(f"Player Hikari: {set2}")
    print(f"Player Kouji: {set3}")
    print(f"Player Yuki: {set4}")

    print()

    print(f"{DISTINCT} {all_achievements}")

    print()

    print(f"{COMMON} {common_achievements}")

    print()

    print(f"Only Yukina has: {unique_achievements1}")
    print(f"Only Hikari has: {unique_achievements2}")
    print(f"Only Kouji has: {unique_achievements3}")
    print(f"Only Yuki has: {unique_achievements4}")

    print()

    print(f"Yukina {MISSING} {all_achievements.difference(set1)} ")
    print(f"Hikari {MISSING} {all_achievements.difference(set2)}")
    print(f"Kouji {MISSING} {all_achievements.difference(set3)}")
    print(f"Yuki {MISSING} {all_achievements.difference(set4)}")
