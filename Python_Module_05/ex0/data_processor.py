#!/usr/bin/env python3


from abc import ABC, abstractmethod
from typing import Any

# ---- Global constants
HEADER: str = "=== Code Nexus - Data Processor ==="


# ---- Code
class DataError(Exception):

    def __init__(self, message: str = "Unknown DataError!") -> None:
        super().__init__(message)


class DataProcessor(ABC):

    def __init__(self) -> None:
        self._data_holder: list[tuple[int, str]] = []
        self._counter: int = 0

    @abstractmethod
    def validate(self, data: Any) -> bool:
        pass

    @abstractmethod
    def ingest(self, data: Any) -> None:
        pass

    def output(self) -> tuple[int, str]:
        if not self._data_holder:
            raise DataError("No oldest value to return.")

        oldest_value: tuple[int, str] = self._data_holder.pop(0)
        return oldest_value


class NumericProcessor(DataProcessor):
    def __init__(self) -> None:
        super().__init__()

    @staticmethod
    def _is_number(value: Any) -> bool:
        return isinstance(value, (int, float)) and not isinstance(value, bool)

    def validate(self, data: Any) -> bool:
        if isinstance(data, list):
            return all(self._is_number(n) for n in data)

        return self._is_number(data)

    def ingest(self, data: int | float | list[int | float]) -> None:
        if not self.validate(data):
            raise DataError("Improper numeric data")

        values: list[int | float]

        if isinstance(data, list):
            values = data

        else:
            values = [data]

        for value in values:
            self._data_holder.append((self._counter, str(value)))
            self._counter += 1


class TextProcessor(DataProcessor):
    def __init__(self) -> None:
        super().__init__()

    @staticmethod
    def _is_str(value: Any) -> bool:
        return isinstance(value, str)

    def validate(self, data: Any) -> bool:
        if isinstance(data, list):
            return all(self._is_str(s) for s in data)

        return self._is_str(data)

    def ingest(self, data: str | list[str]) -> None:
        if not self.validate(data):
            raise DataError("Improper text data")

        values: list[str]

        if isinstance(data, list):
            values = data

        else:
            values = [data]

        for value in values:
            self._data_holder.append((self._counter, value))
            self._counter += 1


class LogProcessor(DataProcessor):
    def __init__(self) -> None:
        super().__init__()

    @staticmethod
    def _is_dict(value: Any) -> bool:
        return (isinstance(value, dict)
                and all(isinstance(k, str) for k in value)
                and all(isinstance(v, str) for v in value.values()))

    def validate(self, data: Any) -> bool:
        if isinstance(data, list):
            return all(self._is_dict(d) for d in data)

        return self._is_dict(data)

    def ingest(self, data: dict[str, str] | list[dict[str, str]]) -> None:
        if not self.validate(data):
            raise DataError("Improper log data")

        values: list[dict[str, str]]

        if isinstance(data, list):
            values = data

        else:
            values = [data]

        for value in values:
            entry: str = ": ".join(value.values())

            self._data_holder.append((self._counter, entry))
            self._counter += 1


def main() -> None:

    proc = NumericProcessor()

    print("Testing Numeric Processor...")

    print(f" Trying to validate input '42': {proc.validate(42)}")
    print(f" Trying to validate input 'Hello': {proc.validate("Hello")}")

    print(" Test invalid ingestion of string 'foo' without prior validation:")

    try:
        proc.ingest("foo")

    except DataError as e:
        print(f" Got exception: {e}")

    test_list_num: list[int | float] = [1, 2, 3, 4, 12.4, 34.5, 238.55]

    proc.ingest(test_list_num)

    print(f" Processing data: {test_list_num}")
    print(f" Extracting {len(test_list_num)} values...")

    for _ in range(len(test_list_num)):
        rank, value = proc.output()

        print(f" Numeric value {rank}: {value}")

    print()

    proc_1 = TextProcessor()

    print("Testing Text Processor...")

    print(f" Trying to validate input '42': {proc_1.validate(42)}")

    test_list_str: list[str] = ['Hello', 'Nexus', 'World']

    proc_1.ingest(test_list_str)

    print(f" Processing data: {test_list_str}")
    print(f" Extracting {len(test_list_str)} values...")

    for _ in range(len(test_list_str)):
        rank, value = proc_1.output()

        print(f" Text value {rank}: {value}")

    print()
    proc_2 = LogProcessor()

    print("Testing Log Processor...")

    print(f" Trying to validate input 'Hello': {proc_2.validate('Hello')}")

    test_list_dict: list[dict[str, str]] = [
        {'log_level': 'NOTICE', 'log_message': 'Connection to server'},
        {'log_level': 'ERROR', 'log_message': 'Unauthorized access!!'}
    ]

    proc_2.ingest(test_list_dict)

    print(f" Processing data: {test_list_dict}")
    print(f" Extracting {len(test_list_dict)} values...")

    for _ in range(len(test_list_dict)):
        rank, value = proc_2.output()

        print(f" Log entry {rank}: {value}")


# ---- Import guard
if __name__ == "__main__":
    # This line runs the block of code if we call the program DIRECTLY,
    # but will not do so, if we importing it.

    print(HEADER)
    print()
    main()
