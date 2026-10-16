#!/usr/bin/env python3


from ex0 import CreatureFactory, FlameFactory, AquaFactory


# ---- Global Constants
FACTORY_TEST: str = "Testing factory"
BATTLE_TEST: str = "Testing battle"


# ---- Code
def factory_tester(factory: CreatureFactory) -> None:
    """
    """

    print(FACTORY_TEST)

    base = factory.create_base()

    evolved = factory.create_evolved()

    print(f"{base.describe()}\n{base.attack()}")

    print(f"{evolved.describe()}\n{evolved.attack()}")


def battle_tester(
        factory_1: CreatureFactory,
        factory_2: CreatureFactory
        ) -> None:
    """
    """

    print(BATTLE_TEST)

    base_1 = factory_1.create_base()

    base_2 = factory_2.create_base()

    print(
            f"{base_1.describe()}\n vs.\n{base_2.describe()}\n fight!"
            f"\n{base_1.attack()}\n{base_2.attack()}"
    )


# ---- Run the Code
if __name__ == "__main__":

    # This line runs the above block of code, IF we call the program DIRECTLY!
    # If it is an import, then the code won't run.

    factory_tester(FlameFactory())

    print()

    factory_tester(AquaFactory())

    print()

    battle_tester(FlameFactory(), AquaFactory())
