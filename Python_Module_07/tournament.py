#!/usr/bin/env python3


from ex2 import (BattleStrategy, CreatureStrategyMatchingError, NormalStrategy,
                 AggressiveStrategy, DefensiveStrategy)
from ex1 import HealingCreatureFactory, TransformCreatureFactory
from ex0 import CreatureFactory, FlameFactory, AquaFactory


# ---- Golbal Contants
BANNER: str = "*** Tournament ***"
CURRENT_FIGHTERS: str = "opponents involved"
CURRENT_FIGHT: str = "* Battle *"
FIGHT_START: str = "now fight!"
ERROR: str = "Battle error, aborting tournament:"


# ---- Code
def tournament(
        fighters_list: list[tuple[CreatureFactory, BattleStrategy]]
) -> None:
    """
    """

    print(BANNER)

    print(f"{len(fighters_list)} {CURRENT_FIGHTERS}\n")

    for i in range(len(fighters_list)):
        for j in range(i + 1, len(fighters_list)):
            fighter_1 = fighters_list[i][0].create_base()

            fighter_2 = fighters_list[j][0].create_base()

            strategy_1 = fighters_list[i][1]

            strategy_2 = fighters_list[j][1]

            print(CURRENT_FIGHT)

            print(f"{fighter_1.describe()}\n vs.\n{fighter_2.describe()}")

            print(f" {FIGHT_START}")

            try:
                print(
                        f"{strategy_1.act(fighter_1)}\n"
                        f"{strategy_2.act(fighter_2)}\n"
                )

            except CreatureStrategyMatchingError as e:
                print(f"{ERROR} {e}\n")

                return


# ---- Run the Code
if __name__ == "__main__":

    # This line runs the above block of code, IF we call the program DIRECTLY!
    # If it is an import, then the code won't run.

    print("Tournament 0 (basic)")

    print(" [ (Flameling+Normal), (Healing+Defensive) ]")

    tournament(
            [(FlameFactory(), NormalStrategy()),
             (HealingCreatureFactory(), DefensiveStrategy())]
    )

    print("Tournament 1 (error)")

    print(" [ (Flameling+Aggressive), (Healing+Defensive) ]")

    tournament(
            [(FlameFactory(), AggressiveStrategy()),
             (HealingCreatureFactory(), DefensiveStrategy())]
    )

    print("Tournament 2 (multiple)")

    print(" [ (Aquabub+Normal), (Healing+Defensive), (Transform+Aggressive) ]")

    tournament(
            [(AquaFactory(), NormalStrategy()),
             (HealingCreatureFactory(), DefensiveStrategy()),
             (TransformCreatureFactory(), AggressiveStrategy())]
    )

    print("Tournament 3 (solo)")

    print(" [ (Flameling+Normal) ]")

    tournament([(FlameFactory(), NormalStrategy())])
