import random


def bg_square(color_index: int) -> str:
    """This function takes a number as input
    which stands for the color of the walls
        Args:
            color: number of a color
        Returns:
            a string which fills a cell in the terminal with a colored block
    """

    return f"\033[48;5;{color_index}m  \033[0m"


def change_color() -> int:
    """This function picks a random number between 0 and 255

        Args:
            None
        Returns:
            it return a random number
    """
    color: int = random.randint(0, 255)
    return (color)
