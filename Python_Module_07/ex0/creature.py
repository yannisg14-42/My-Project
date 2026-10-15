#!/usr/bin/env python3


from abc import ABC, abstractmethod


# ---- Code
class Creature(ABC):

    """
    """

    def __init__(
            self,
            creature_name: str,
            creature_type: str
            ) -> None:
        self._creature_name = creature_name

        self._creature_type = creature_type

    def __str__(self) -> str:
        return (
                f"{self._creature_name} is a "
                f"{self._creature_type} type Creature"
        )

    def describe(self) -> None:
        print(self)

    @abstractmethod
    def attack(self) -> None:
        pass
