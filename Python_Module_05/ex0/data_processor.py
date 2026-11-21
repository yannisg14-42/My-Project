#!/usr/bin/env python3


from abc import ABC, abstractmethod
from typing import Any


# ---- Global constants
HEADER: str = "=== Code Nexus - Data Processor"


# ---- Code
class DataProcessor(ABC):
    """
    """

    @abstractmethod
    def validate(self, data: Any) -> bool:
        pass

    @abstractmethod
    def ingest(self, data: Any) -> None:
        pass

    def output(self) -> tuple[int, str]:
        
