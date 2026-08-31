from .file_reader import parse_coordinate
import sys


class SizeError(Exception):
    pass


class LessThanZeroError(Exception):
    pass


class OutOfBoundsError(Exception):
    pass


class PerfectError(Exception):
    pass


def check_data(data: dict[str, str]) -> None:
    """This function checks the data fro the config file
        Args:
            data: contains the data from the config file
        Returns:
            None
    """

    width: int = int(data["WIDTH"])
    height: int = int(data["HEIGHT"])
    try:
        entry: tuple[int, int] = parse_coordinate(data["ENTRY"])
        maze_exit: tuple[int, int] = parse_coordinate(data["EXIT"])
    except IndexError as e:
        print(f"{e.__class__.__name__}The entry and Exit" +
              "point must have the format: int,int")
        sys.exit(1)
    if width < 11 or height < 7:
        raise SizeError("The width must be at least 10 and height at least 7!")
    if min(*entry, *maze_exit) < 0:
        raise LessThanZeroError(
            "The Entry and Exit points must be greater than Zero")
    if any(x >= width or y >= height for x, y in (entry, maze_exit)):
        raise OutOfBoundsError(
            "The Entry and Exit points must be inside the Maze")
    if data["PERFECT"] not in ("True", "False"):
        raise PerfectError("The value of 'PERFECT' must be True or False")
