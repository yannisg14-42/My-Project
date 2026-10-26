#!/usr/bin/env python3


from ex0.creature import Creature
from .capabilities import HealCapability, TransformCapability


# ---- Code
class Sproutling(Creature, HealCapability):
    """
    """

    def __init__(self) -> None:
        super().__init__("Sproutling", "Grass")

        self._creature_attack = "Vine Whip"

    def attack(self) -> str:
        return (
                f"{self._creature_name} uses "
                f"{self._creature_attack}!"
        )

    def heal(self, target: str | None = None) -> str:
        if target is None:
            return (f"{self._creature_name} heals itself for a small amount")

        return (
                f"{self._creature_name} heals itself and {target} "
                f"for a small amount"
        )


class Bloomelle(Creature, HealCapability):
    """
    """

    def __init__(self) -> None:
        super().__init__("Bloomelle", "Grass/Fairy")

        self._creature_attack = "Petal Dance"

    def attack(self) -> str:
        return (
                f"{self._creature_name} uses "
                f"{self._creature_attack}!"
        )

    def heal(self, target: str | None = None) -> str:
        if target is None:
            return (
                    f"{self._creature_name} heals itself and others "
                    f"for a large amount"
            )

        return (
                f"{self._creature_name} heals itself and {target} "
                f"for a large amount"
        )


class Shiftling(Creature, TransformCapability):
    """
    """

    def __init__(self) -> None:
        super().__init__("Shiftling", "Normal")

        TransformCapability.__init__(self)

        self._creature_attack = "attacks normally"

        self._creature_attack_modified = "performs a boosted strike"

    def transform(self) -> str:
        self._is_transformed = True

        return (f"{self._creature_name} shifts into a sharper form!")

    def attack(self) -> str:
        if not self._is_transformed:
            return (f"{self._creature_name} {self._creature_attack}.")

        else:
            return (f"{self._creature_name} {self._creature_attack_modified}!")

    def revert(self) -> str:
        self._is_transformed = False
        return (f"{self._creature_name} returns to normal.")


class Morphagon(Creature, TransformCapability):
    """
    """

    def __init__(self) -> None:
        super().__init__("Morphagon", "Normal/Dragon")

        TransformCapability.__init__(self)

        self._creature_attack = "attacks normally"

        self._creature_attack_modified = "unleashes a devastating morph strike"

    def transform(self) -> str:
        self._is_transformed = True

        return (f"{self._creature_name} morphs into a dragonic battle form!")

    def attack(self) -> str:
        if not self._is_transformed:
            return (f"{self._creature_name} {self._creature_attack}.")

        else:
            return (f"{self._creature_name} {self._creature_attack_modified}!")

    def revert(self) -> str:
        self._is_transformed = False
        return (f"{self._creature_name} stabilizes its form.")
