#!/usr/bin/env python3


from abc import ABC, abstractmethod
from ex0.creature import Creature


# ---- Code
class BattleStrategy(ABC):
    """
    """

    @abstractmethod
    def act(self, fighter: Creature) -> str:
        pass

    @abstractmethod
    def is_valid(self, fighter: Creature) -> bool:
        pass


class CreatureStrategyMatchingError(Exception):
    """
    """

    def __init__(
            self,
            message: str = "Unknown Creature-Strategy Matching Error!"
    ) -> None:
        super().__init__(message)
