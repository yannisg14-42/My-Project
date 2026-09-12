#!/usr/bin/env python3

# >>>>Global Constants<<<<

HEADER: str = "=== Garden Watering System ===\n"
TESTING_ONLY_VALID: str = "Testing valid plants..."
TESTING_INVALID: str = "\nTesting invalid plants..."
OPENING_WATER_SYSTEM: str = "Opening watering system"
CLOSE_WATER_SYSTEM: str = "Closing watering system"
RETURN_TO_MAIN: str = ".. ending tests and returning to main"
PROGRAM_END: str = "\nCleanup always happens, even with errors!"


class GardenError(Exception):

    """
    The main class of our custom errors, that itself,
    inherit from Exception

    Args:
        message: the error message we display when an error
        is caught
    """

    def __init__(self,
                 message: str = "Unknown garden error"
                 ) -> None:
        super().__init__(message)


class PlantError(GardenError):

    """
    A child class of GardenError
    """

    def __init__(self,
                 message: str = "Unknown plant error"
                 ) -> None:
        super().__init__(message)


def water_plant(plant_name: str) -> None:

    """
    This function raises if plant_name: str != plant_name.capitalize(),
    else print a success message.

    Args:
        plant_name: the str we are checking

    Returns:
        None

    Raises:
        a PlantError if plant_name != plant_name.capitalize()
    """


    if plant_name != plant_name.capitalize():
        raise PlantError(f"Invalid plant name to water: '{plant_name}'")

    print(f"Watering {plant_name}: [OK]")


def test_watering_system(plants_to_test: list[str]) -> None:

    """
    This function test that whether  water_plant run as intended. If no issue,
    print normally, else if it raises a PlantError, except catches it,
    display an error message, and exit to main. The finally block always
    runs whatever the exit sequence and print a message to prove it.

    Args:
        plants_to_test: a list[str], that hold all the value to test

    Returns:
        None
    """

    print(OPENING_WATER_SYSTEM)

    try:
        for plant_name in plants_to_test:
            water_plant(plant_name)

    except PlantError as e:
        print(f"Caught PlantError: {e}\n{RETURN_TO_MAIN}")

    finally:
        print(CLOSE_WATER_SYSTEM)


# >>>>Runs the Code<<<<

if __name__ == "__main__":

    # This line runs the block of if we call the program DIRECTLY,
    # but will not, if it is imported.

    print(HEADER)

    print(TESTING_ONLY_VALID)

    test_watering_system(["Tomato", "Lettuce", "Carrots"])

    print(TESTING_INVALID)

    test_watering_system(["Tomato", "lettuce", "Carrots"])

    print(PROGRAM_END)
