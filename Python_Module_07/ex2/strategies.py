#!/usr/bin/env python3


from ex0.creature import Creature
from .battle_strategy import BattleStrategy, CreatureStrategyMatchingError
from ex1.capabilities import TransformCapability, HealCapability


# ---- Code
class NormalStrategy(BattleStrategy):
    """
    """

    def act(self, fighter: Creature) -> str:
        return fighter.attack()

    def is_valid(self, fighter: Creature) -> bool:
        return True


class AggressiveStrategy(BattleStrategy):
    """
    """

    def act(self, fighter: Creature) -> str:
        if not isinstance(fighter, TransformCapability):
            raise CreatureStrategyMatchingError(
                    f"Invalid Creature '{fighter.get_creature_name()}' "
                    f"for this aggressive strategy"
            )

        return (
                f"{fighter.transform()}\n{fighter.attack()}\n"
                f"{fighter.revert()}"
        )

    def is_valid(self, fighter: Creature) -> bool:
        return isinstance(fighter, TransformCapability)


class DefensiveStrategy(BattleStrategy):
    """
    """

    def act(self, fighter: Creature) -> str:
        if not isinstance(fighter, HealCapability):
            raise CreatureStrategyMatchingError(
                    f"Invalid Creature '{fighter.get_creature_name()}' "
                    f"for this defensive strategy"
            )

        return (f"{fighter.attack()}\n{fighter.heal()}")

    def is_valid(self, fighter: Creature) -> bool:
        return isinstance(fighter, HealCapability)
