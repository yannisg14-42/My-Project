#!/usr/bin/env python3


import math


# ---- Global Constants
BANNER: str = "=== Game Coordinate System ==="
ENTER_COORDINATES: str = "Enter new coordinates as floats in format 'x,y,z': "
COORDINATE_SET_1: str = "Get first set of coordinates"
COORDINATE_SET_2: str = "Get second set of coordinates"
TUPLE_CREATED: str = "Got a first tuple:"
TUPLE_CREATED_1: str = "Got a second tuple"
ERROR: str = "Error on parameter"


# ---- Code's Logic
def get_player_pos() -> tuple[float, ...]:

    """
    A function that use input() to ask the user to write 3 str in the prompt
    If the user type less than 3 str or they are not separated by ',', it
    print() an Error message and keep returning prompt, until the user enter
    exactly 3 str separated by ','.
    If the user entry is correct, now the program try to float() those str and
    put them in a list[float].
    If float() fails, then it raises and except catches a Valuerror. To print()
    the exact Error, we put it inside a variables in a loop so we can get the
    index of where it fails. Then we print the Error message.
    Else if float() succeed, then we return a tuple() of our list[float]

    Returns:
        a tuple[float, ...] meaning a tuple of any float, that is our set of
        coordinates
    """

    # ---- Input Logic; keep repeating until we enter a correct syntax
    while True:
        get_coordinates: str = input(ENTER_COORDINATES)

        coordinates: list[str] = get_coordinates.split(",")

        if len(coordinates) != 3:
            print("Invalid syntax")
            continue

        # ---- Tuple creation logic and Errors handling
        index: int = 0

        temp: list[float] = []
        try:
            while index < 3:
                c: float = float(coordinates[index])

                temp.append(c)
                index += 1

        except ValueError as e:
            print(f"{ERROR} '{coordinates[index]}': {e}")
            continue

        return tuple(temp)


def get_distance(
        first_tuple: tuple[float, ...],
        second_tuple: tuple[float, ...]
        ) -> float:

    """
    A simple functionthat calculate the distance between points of
    coordinates (x,y,z)

    Args:
        first_tuple: the first set of coordinates stored in a tuple
        second_tuple: the second set of coordinates stored in a tuple

    Returns:
        the distance between the point by doing doing math.sqrt(float)
    """

    total: float = 0.0

    index: int = 0

    while index < 3:
        sub_operation: float = (second_tuple[index] - first_tuple[index])**2

        total += sub_operation
        index += 1

    return math.sqrt(total)


# ---- Runs the Code
if __name__ == "__main__":

    # This line runs the block of if we call the program DIRECTLY,
    # but will not, if it is imported.

    print(BANNER)

    print()

    print(COORDINATE_SET_1)

    first_tuple: tuple[float, ...] = get_player_pos()

    print(f"{TUPLE_CREATED} {first_tuple}")

    print(
            f"It includes: X={first_tuple[0]}, Y={first_tuple[1]}, "
            f"Z={first_tuple[2]}"
    )

    distance_1: float = round(get_distance(first_tuple, (0.0, 0.0, 0.0)), 4)

    print(f"Distance to center: {distance_1}")

    print()

    print(COORDINATE_SET_2)

    second_tuple: tuple[float, ...] = get_player_pos()

    print(f"{TUPLE_CREATED_1} {second_tuple}")

    print(
            f"It includes: X={second_tuple[0]}, Y={second_tuple[1]}, "
            f"Z={second_tuple[2]}"
    )

    distance_2: float = round(get_distance(first_tuple, second_tuple), 4)

    print(f"Distance between the 2 sets of coordinates: {distance_2}")
