#!/usr/bin/env python3


from abc import ABC, abstractmethod
from typing import Any, Protocol

# ---- Global constants
TITLE: str = "=== Code Nexus - Data Pipeline ==="
HEADER: str = "== DataStream statistics =="


# ---- Code
# ---- Exception class
class DataError(Exception):

    def __init__(self, message: str = "Unknown DataError!") -> None:
        super().__init__(message)


# ---- Parent class
class DataProcessor(ABC):

    def __init__(self, processor_type: str) -> None:
        self._processor_type: str = processor_type
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

    def get_name(self) -> str:
        return self._processor_type

    def total_processed(self) -> int:
        return self._counter

    def remaining(self) -> int:
        return len(self._data_holder)


# ---- Child classes
class NumericProcessor(DataProcessor):
    def __init__(self) -> None:
        super().__init__("Numeric Processor")

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
        super().__init__("Text Processor")

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
        super().__init__("Log Processor")

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


# ---- Protocol class
class ExportPlugin(Protocol):

    def process_output(self, data: list[tuple[int, str]]) -> None:
        ...


# ---- Statistics class
class DataStream:

    def __init__(self) -> None:
        self._processors: list[DataProcessor] = []

    def register_processor(self, proc: DataProcessor) -> None:
        self._processors.append(proc)

    def process_stream(self, stream: list[Any]) -> None:
        for element in stream:
            for proc in self._processors:
                is_valid: bool = proc.validate(element)

                if is_valid:
                    proc.ingest(element)
                    break

            else:
                print(
                      f"DataStream error - Can't process "
                      f"element in stream: {element}"
                )

    def output_pipeline(self, nb: int, plugin: ExportPlugin) -> None:
        for proc in self._processors:
            data: list[tuple[int, str]] = []

            for _ in range(min(nb, proc.remaining())):
                data.append(proc.output())

            plugin.process_output(data)

    def print_processors_stats(self) -> None:
        print(HEADER)

        if not self._processors:
            print("No processor found, no data")

        else:
            for proc in self._processors:
                proc_type: str = proc.get_name()

                proc_processed: int = proc.total_processed()

                proc_remaining: int = proc.remaining()

                print(
                      f"{proc_type}: total {proc_processed} "
                      f"items processed, remaining "
                      f"{proc_remaining} on processor"
                )


class CSVExportPlugin:

    def process_output(self, data: list[tuple[int, str]]) -> None:
        print("CSV Output:")

        print(",".join(value for _, value in data))


class JSONExportPlugin:

    def process_output(self, data: list[tuple[int, str]]) -> None:
        print("JSON Output:")

        items = ", ".join(f'"item_{rank}": "{value}"' for rank, value in data)

        print("{" + items + "}")


# ---- Main
def main() -> None:

    print("Initialize Data Stream...")

    stream = DataStream()

    stream.print_processors_stats()
    print()

    print("Registering Numeric Processor")

    num_proc = NumericProcessor()

    stream.register_processor(num_proc)

    batch: list[Any] = [
        'Hello world',
        [3.14, -1, 2.71],
        [
            {'log_level': 'WARNING',
             'log_message': 'Telnet access! Use ssh instead'},
            {'log_level': 'INFO',
             'log_message': 'User wil is connected'},
        ],
        42,
        ['Hi', 'five'],
    ]
    print()

    print(f"Send first batch of data on stream: {batch}")

    stream.process_stream(batch)

    stream.print_processors_stats()
    print()

    print("Registering other data processors")

    text_proc = TextProcessor()

    log_proc = LogProcessor()

    stream.register_processor(text_proc)

    stream.register_processor(log_proc)

    print("Send the same batch again")

    stream.process_stream(batch)

    stream.print_processors_stats()
    print()

    print(
          "Consume some elements from the data processors: "
          "Numeric 3, Text 2, Log 1"
    )

    for _ in range(3):
        num_proc.output()

    for _ in range(2):
        text_proc.output()

    log_proc.output()

    stream.print_processors_stats()

    print("Send 3 processed data from each processor to a CSV plugin:")

    stream.output_pipeline(3, CSVExportPlugin())

    stream.print_processors_stats()
    print()

    print("Send 5 processed data from each processor to a JSON plugin:")

    stream.output_pipeline(5, JSONExportPlugin())

    stream.print_processors_stats()


# ---- Import guard
if __name__ == "__main__":
    # This line runs the block of code if we call the program DIRECTLY,
    # but will not do so, if we importing it.

    print(TITLE)
    print()

    main()
