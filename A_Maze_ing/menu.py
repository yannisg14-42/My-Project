from .show_maze import maze_viewer, animate_path
from .color import change_color
from src.mazegen.mazegen import MazeGenerator, store_maze
from maze_functions.file_reader import parse_coordinate
import random


def show_menu(maze: MazeGenerator,
              config_data: dict[str, str],
              path: bool = True,
              color: int = 42
              ) -> None:
    """This function shows the menu and handles theuser input

        Args:
            maze: an instance of the MazeGenerator class
            config_data: a dictionary of the data from the config.txt file
            path: a bool that checks if the path is shown or not
            color: an integer to choose the color

        Returns:
            None
        """
    maze_entry: tuple[int, int] = parse_coordinate(config_data["ENTRY"])
    maze_exit: tuple[int, int] = parse_coordinate(config_data["EXIT"])
    while True:
        print("====MAZE GENERATOR====")
        print("1) Change color")
        print("2) New maze")
        if path:
            print("3) Show shortest path")
        else:
            print("3) Hide shortest path")
        print("4) Quit")
        try:
            number: int = int(input("What do you wanna do?"))
            if number == 1:
                color = change_color()
                maze_viewer(maze.grid,
                            maze_entry, maze_exit,
                            maze.blocked, color)

            elif number == 2:
                new_maze: MazeGenerator = MazeGenerator(
                    int(config_data["WIDTH"]),
                    int(config_data["HEIGHT"]),
                    maze_entry,
                    maze_exit,
                    random.randint(0, 256),
                    config_data["PERFECT"] in ("True", "true")
                    )
                new_maze.generate()
                maze = new_maze
                store_maze(maze.grid, maze_entry, maze_exit,
                           config_data["OUTPUT_FILE"])
                maze_viewer(maze.grid,
                            maze_entry,
                            maze_exit,
                            maze.blocked,
                            color)
            elif number == 3:
                if path:
                    animate_path(maze.grid, maze_entry, maze_exit,
                                 maze.blocked, maze.solution, color)
                    path = False
                else:
                    maze_viewer(maze.grid, maze_entry, maze_exit,
                                maze.blocked, color)
                    path = True
            elif number == 4:
                print("bye!")
                exit(0)
            else:
                print("WRONG INPUT!!!")
        except ValueError as e:
            print(f"{e.__class__.__name__}: Enter a number between 1 and 4!")
