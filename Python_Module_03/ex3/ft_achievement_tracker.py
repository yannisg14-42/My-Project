#!/usr/bin/env python3


import random

# ---- Global Constant
HEADER: str = "=== Achievement Tracker System ==="
DISTINCTS: str = "All distinct achievements:"
COMMON: str = "Common achievements:"
MISSING: str = "is missing:"
ACHIEVEMENTS: list[str] = [
    'Boss Slayer', 'Collector Supreme', 'Crafting Genius',
    'First Steps', 'Master Explorer', 'Sharp Mind', 'Speed Runner',
    'Strategist', 'Survivor', 'Treasure Hunter', 'Unstoppable',
    'Untouchable', 'World Savior', 'Weapon of the Faithful',
    'Darkin Blade', 'Spark of Zaun', 'Unbroken Faith', 'Rune Mage',
    'Ice Witch', 'Virtuoso'
]


# ---- Code
# ---- set generation
def gen_player_achievements() -> set[str]:
    """
    A function that generate a random set by picking in
    a given list of str.
    """

    k: int = random.randint(10, 15)

    player_achievement: list[str] = random.sample(ACHIEVEMENTS, k)

    return set(player_achievement)


# ---- main responsible of tests
def main() -> None:
    """
    The main that is responsible of testing.

    Print each player with their achievements as set.
    print all distinct achievements acquired.
    print all achievements shared across all players.
    print all achievements unique to each player.
    print all achievements missed by each player.
    """

    print(HEADER)

    print()

    players: list[str] = ["Yukina", "Hikari", "Kouji", "Yuki"]

    achievements: list[set[str]] = []

    i: int = 0

    while i < len(players):
        achievements.append(gen_player_achievements())
        i += 1

    i = 0

    all_achievements: set[str] = set()

    common_achievements: set[str] = achievements[0]

    while i < len(players):
        print(f"Player {players[i]}: {achievements[i]}")

        all_achievements = (
            all_achievements.union(achievements[i])
        )

        common_achievements = (
            common_achievements.intersection(achievements[i])
        )
        i += 1

    print()

    print(f"{DISTINCTS} {all_achievements}")

    print()

    print(f"{COMMON} {common_achievements}")

    print()

    i = 0

    while i < len(players):
        others: set[str] = set()

        j = 0

        while j < len(achievements):
            if j == i:
                j += 1
                continue

            others = others.union(achievements[j])
            j += 1

        unique_achievements: set[str] = achievements[i].difference(others)

        print(f"Only {players[i]} has: {unique_achievements}")
        i += 1

    i = 0

    print()

    all_items: set[str] = set(ACHIEVEMENTS)

    while i < len(players):
        missing_achievements: set[str] = (
            all_items.difference(achievements[i])
        )

        print(f"{players[i]} {MISSING} {missing_achievements}")
        i += 1


# ---- Runs the Code
if __name__ == "__main__":
    # This line runs the block of if we call the program DIRECTLY,
    # but will not, if it is imported.

    main()
