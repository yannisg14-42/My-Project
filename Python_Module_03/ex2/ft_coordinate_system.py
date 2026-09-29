#!/usr/bin/env python3


import math


# >>>Global Constants<<<

BANNER: str = "=== Game Coordinate System ==="
ENTER_COORDINATES: str = "Enter new coordinates as floats in format 'x,y,z': "
COORDINATE_SET_1: str = "Get first set of coordinates"
COORDINATE_SET_2: str = "Get second set of coordinates"
WRONG_SYNTAX: str = "Invalid syntax"
TUPLE_CREATED: str = "Got a first tuple:"


def get_player_pos() -> None:

    """

    """

    set_coordinates: tuple[float] = ()

    print(COORDINATE_SET_1)

    while True:
        try:
            get_coordinates_1: float = float(input(ENTER_COORDINATES))
            set_coordinates.append(get_coordinates_1)
            break

        except:
            print(WRONG_SYNTAX)

    print(f"{TUPLE_CREATED} {set_coordinates}")


 # >>>>Runs the Code<<<<

if __name__ == "__main__":

    # This line runs the block of if we call the program DIRECTLY,
    # but will not, if it is imported.

    get_player_pos()
