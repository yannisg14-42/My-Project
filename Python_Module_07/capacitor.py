#!/usr/bin/env python3


from ex1 import HealingCreatureFactory, TransformCreatureFactory
from ex1.heal import HealCapability
from ex1.transform import TransformCapability
from ex0 import CreatureFactory


# ---- Global Constants
HEAL_BANNER: str = "Testing Creature with healing capability"
TRANSFORM_BANNER: str = "Testing Creature with transform capability"


# ---- Code
def healing_factory_tester(factory: CreatureFactory) -> None:
    """
    """

    base = factory.create_base()

    evolved = factory.create_evolved()

    print(HEAL_BANNER)

    print(" base:")

    if isinstance(base, HealCapability):
        print(f"{base.describe()}\n{base.attack()}\n{base.heal()}")

    else:
        print(f"{base}, and not an Instance of HealCapability!")

    print(" evolved:")

    if isinstance(evolved, HealCapability):
        print(f"{evolved.describe()}\n{evolved.attack()}\n{evolved.heal()}")

    else:
        print(f"{evolved}, and not an Instance of HealCapability!")


def transform_factory_tester(factory: CreatureFactory) -> None:
    """
    """

    base = factory.create_base()

    evolved = factory.create_evolved()

    print(TRANSFORM_BANNER)

    print(" base:")

    if isinstance(base, TransformCapability):
        print(
                f"{base.describe()}\n{base.attack()}\n{base.transform()}\n"
                f"{base.attack()}\n{base.revert()}"
        )

    else:
        print(f"{base}, and not an Instance of TransformCapability!")

    print(" evolved:")

    if isinstance(evolved, TransformCapability):
        print(
                f"{evolved.describe()}\n{evolved.attack()}\n"
                f"{evolved.transform()}\n{evolved.attack()}\n"
                f"{evolved.revert()}"
        )

    else:
        print(f"{evolved}, and not an Instance of TransformCapability!")


# ---- Run the Code
if __name__ == "__main__":

    # This line runs the above block of code, IF we call the program DIRECTLY!
    # If it is an import, then the code won't run.

    healing_factory_tester(HealingCreatureFactory())

    print()

    transform_factory_tester(TransformCreatureFactory())
