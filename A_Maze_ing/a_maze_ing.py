import sys
from maze_functions.file_reader import read_file, parse_coordinate
from src.mazegen.mazegen import MazeGenerator, store_maze
from maze_functions.show_maze import maze_viewer
from maze_functions.menu import show_menu
from maze_functions.data_validator import (check_data,
                                           SizeError,
                                           LessThanZeroError,
                                           OutOfBoundsError,
                                           PerfectError)


def main(config_data: dict[str, str]) -> None:
    """This function is the main function of the program it
    creates and show the maze and displays the menu for the user interactions.

        Args:
            config_data: this is the data from the config.txt file

        Returns:
            None
    """
    entry: tuple[int, int] = parse_coordinate(config_data["ENTRY"])
    end: tuple[int, int] = parse_coordinate(config_data["EXIT"])
    maze = MazeGenerator(
        int(config_data["WIDTH"]),
        int(config_data["HEIGHT"]),
        entry,
        end,
        int(config_data["SEED"]),
        config_data["PERFECT"] in ("True", "true")
    )
    maze.generate()
    store_maze(maze.grid, entry, end,
               config_data["OUTPUT_FILE"])
    maze_viewer(maze.grid, entry, end, maze.blocked)
    show_menu(maze, config_data)


if __name__ == "__main__":

    if len(sys.argv) < 2:
        print("Usage: python a_maze_ing.py <config_file>")
        sys.exit(1)  # Beende das Programm mit Fehlercode 1

    config_file: str = sys.argv[1]
    try:
        config_data: dict[str, str] = read_file(config_file)
        if "--perfect" in sys.argv:
            config_data["PERFECT"] = "True"
            print("PERFECT MODE IS ACTIVATED!!!")
        check_data(config_data)
        main(config_data)
    except (SizeError,
            LessThanZeroError,
            OutOfBoundsError,
            ValueError,
            PerfectError
            ) as e:
        print(e)
    except KeyError as e:
        print(f"{e.__class__.__name__}: Check the keys in your config file." +
              f"The {e} - key is missing.")
