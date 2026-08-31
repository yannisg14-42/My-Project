import re
import sys


class FormatError(Exception):
    pass


def read_file(file: str) -> dict[str, str]:
    """This function reads a file and stores the content in to a dictionary

        Args:
            file: the text of the config.txt file

        Returns:
            a dictionary with the key and value pairs from the given file
    """
    data: dict[str, str] = {}
    try:
        with open(file, "r") as f:
            for line in f:
                line = line.strip()
                if not line or line.startswith("#"):
                    continue
                if re.match(r'^[^=]*=[^=]*$', line):
                    value = line.split("=")
                    data[value[0]] = value[1]
                else:
                    raise FormatError(
                        "The Format of a Key Value " +
                        "pair in the config.txt file must look like KEY=VALUE")
    except (FileNotFoundError, IndexError, FormatError) as e:
        print(f"{e.__class__.__name__}: {e}")
        sys.exit(1)
    return data


def parse_coordinate(value: str) -> tuple[int, int]:
    """This function takes a string and changes it into a tuple

        Args:
            value: is a string with two numbers

        Returns:
            it returns a tuple of ints
    """
    parts = value.split(",")
    return (int(parts[0]), int(parts[1]))
