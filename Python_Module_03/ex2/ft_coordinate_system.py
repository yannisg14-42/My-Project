#!/usr/bin/env python3


import math


# >>>Global Constants<<<

BANNER: str = "=== Game Coordinate System ===\n"
ENTER_COORDINATES: str = "Enter new coordinates as floats in format 'x,y,z': "
COORDINATE_SET_1: str = "Get first set of coordinates"
COORDINATE_SET_2: str = "Get second set of coordinates"
TUPLE_CREATED: str = "Got a first tuple:"

def get_player_pos() -> tuple:

    """

    """
    while True:
        get_coordinates_1: str = input(ENTER_COORDINATES)
        coordinates_1: list[str] = get_coordinates_1.split(",")
        if len(coordinates_1) != 3:
            print("Ivalid syntax")
            continue
        try:
            x: float = float(coordinates_1[0])
            y: float = float(coordinates_1[1])
            z: float = float(coordinates_1[2])
        except ValueError as e:
            print(f"Error on parameter '{e}': {e}")
            continue
        return tuple(x,y,z)

 # >>>>Runs the Code<<<<

if __name__ == "__main__":

    # This line runs the block of if we call the program DIRECTLY,
    # but will not, if it is imported.

    print(BANNER)

    print(COORDINATE_SET_1)

    first_set: tuple = get_player_pos()

    print(f"{TUPLE_CREATED} {first_set}")

    print(f"It includes: X={first_set[0]}, Y={first_set[1]}, Z={first_set[2]}")

    distance_1: float = math.sqrt((0 - first_set[0])**2 + (0 - first_set[1])**2 + (0 - first_set[2])**2)

    print(f"Distance to center: {disatance_1}")

    print("\n")

    print(COORDINATE_SET_2)

    second_set: tuple = get_player_pos()

    print(f"{TUPLE_CREATED} {second_set}")

    print(f"It includes: X={second_set[0]}, Y={second_set[1]}, Z={second_set[2]}")

    distance_2: float = math.sqrt((second_set[0]- first_set[0])**2 + (second_set[1] - first_set[1])**2 + (second_set[2] - first_set[2])**2)

    print(f"Distance between the 2 sets of coordinates: {disatance_2}")
