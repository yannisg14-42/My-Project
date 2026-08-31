from .color import bg_square
from src.mazegen.mazegen import NORTH, EAST, SOUTH
import time


def clear_screen() -> None:
    """This function clears the Terminal"

        Args:
            None

        Returns:
            None
        """
    print("\033[H\033[J", end="")


def maze_viewer(grid: list[list[int]],
                entry: tuple[int, int],
                exit: tuple[int, int],
                blocked: set[tuple[int, int]],
                color: int = 42,
                path: list[tuple[int,  int]] | None = None,
                ) -> None:
    """This function make the maze in the terminal visible

        Args:
            grid: the list of list with integers which stand for each cell
            entry: a tuple with the coordinates of the entry point
            exit: a tuple with the coordinates of the exit point
            blocked: a set of coordinates of the blocked points to display 42
            color: an integer to choose the color
            path: a list of tuples with the coordinates of the solution path

        Returns:
            None
    """
    clear_screen()
    symbol: str = bg_square(color)
    count_x: int = 0
    count_y: int = 0
    line3: list[str] = []
    for x in grid:
        line1: list[str] = [symbol]
        line2: list[str] = [symbol]
        line3 = [symbol]

        count_y = 0
        for y in x:
            line1.append(symbol if y & NORTH else "  ")
            line1.append(symbol)

            if entry == (count_y, count_x):
                line2.append("😄")
            elif exit == (count_y, count_x):
                line2.append("🥳")
            elif path and (count_y, count_x) in path[1:-1]:
                line2.append("🐠")
            elif (count_y, count_x) in blocked:
                line2.append(bg_square(24))
            else:
                line2.append("  ")
            line2.append(symbol if y & EAST else "  ")
            line3.append(symbol if y & SOUTH else "  ")
            line3.append(symbol)
            count_y += 1

        print("".join(line1))
        print("".join(line2))
        count_x += 1
    print("".join(line3))


def animate_path(grid: list[list[int]],
                 entry: tuple[int, int],
                 exit: tuple[int, int],
                 blocked: set[tuple[int, int]],
                 path: list[tuple[int, int]],
                 color: int = 42,
                 delay: float = 0.05,) -> None:
    """This function animates the path

        Args:
            grid: the list of list with integers which stand for each cell
            entry: a tuple with the coordinates of the entry point
            exit: a tuple with the coordinates of the exit point
            blocked: a set of coordinates of the blocked points to display 42
            color: an integer to choose the color
            path: a list of tuples with the coordinates of the solution path
            delay:delaytime

        Returns:
            None
    """
    for i in range(1, len(path) + 1):
        maze_viewer(grid, entry, exit, blocked, color, path[:i])
        time.sleep(delay)
