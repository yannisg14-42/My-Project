#!/usr/bin/env python3


from abc import ABC, abstractmethod


# ---- Code
# ---- Parent Class
class HealCapability(ABC):
    """
    """

    @abstractmethod
    def heal(self, target: str | None = None) -> str:
        pass
