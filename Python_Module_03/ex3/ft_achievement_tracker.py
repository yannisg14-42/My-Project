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

def main() -> None:
    """
    The main
    """

    players: list[str] = ["Yukina", "Hikari", "Kouji", "Yuki"]

    achievements: list[set[str]] = [gen_player_achievement(), gen_player_achievement(), gen_player_achievement(), gen_player_achievement()]

    i: int = 0

    all_achievements: set[str] = set()

    common_achievements: set[str] = set()

    while i < len(players) and i < len(achievements):
        print(f"Player {players[i]}: {achievements[i]}")

        all_achievements: set[str] = all_achievements.union(achievements[i])

        common_achievements: set[str] = common_achievements.intersection(achievements[i])
        i += 1

    print()

    print(f"{DISTINCT} {all_achievements}")

    print()

    print(f"{COMMON} {common_achievements}")

    print()

    i: int  = 0

    while i < len(players) and i < len(achievements):
        missing_achievements: set[str] = all_achievements.difference(achievements[i])

        print(f"{players[i]} {MISSING} {missing_achievements}")
        i += 1

        


# ---- Runs the Code
if __name__ == "__main__":
    # This line runs the block of if we call the program DIRECTLY,
    # but will not, if it is imported.

    print(HEADER)

    print()

    main()    
