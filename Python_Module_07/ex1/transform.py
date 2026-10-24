#!/usr/bin/env python3


from abc import ABC, abstractmethod


# ---- Code
# ---- Parent Class
class TransformCapability(ABC):
    """
    """

    def __init__(self) -> None:
        self._is_transformed = False

    @abstractmethod
    def transform(self) -> str:
        pass

    @abstractmethod
    def revert(self) -> str:
        pass
