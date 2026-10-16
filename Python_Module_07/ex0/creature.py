#!/usr/bin/env python3


from abc import ABC, abstractmethod


# ---- Code
# ---- Parent Class
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

    def describe(self) -> str:
        return str(self)

    @abstractmethod
    def attack(self) -> str:
        pass


# ---- Child Classes
class Flameling(Creature):

    """
    """

    def __init__(self) -> None:
        super().__init__("Flameling", "Fire")

        self._creature_attack: str = "Ember"

    def attack(self) -> str:
        return (
                f"{self._creature_name} uses "
                f"{self._creature_attack}!"
        )


class Pyrodon(Creature):

    """
    """

    def __init__(self) -> None:
        super().__init__("Pyrodon", "Fire/Flying")

        self._creature_attack: str = "Flamethrower"

    def attack(self) -> str:
        return (
                f"{self._creature_name} uses "
                f"{self._creature_attack}!"
        )


class Aquabub(Creature):

    """
    """

    def __init__(self) -> None:
        super().__init__("Aquabub", "Water")

        self._creature_attack: str = "Water Gun"

    def attack(self) -> str:
        return (
                f"{self._creature_name} uses "
                f"{self._creature_attack}!"
        )


class Torragon(Creature):

    """
    """

    def __init__(self) -> None:
        super().__init__("Torragon", "Water")

        self._creature_attack: str = "Hydro Pump"

    def attack(self) -> str:
        return (
                f"{self._creature_name} uses "
                f"{self._creature_attack}!"
        )
