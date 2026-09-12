#!/usr/bin/env python3

# >>>>Global Constants<<<<

HEADER: str = "=== Custom Garden Errors Demo ===\n"
ALL_ERROR_CAUGHT: str = "Testing catching all garden errors"
PROGRAM_END: str = "\nAll custom error types work correctly!"


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


class WaterError(GardenError):

    """
    A child class of GardenError
    """

    def __init__(self,
                 message: str = "Unknown water error"
                 ) -> None:
        super().__init__(message)


def custom_errors_test(test_number: int) -> None:

    """
    This function raises our custom error types

    Returns:
        None

    Raises:
        two custom error types depending on test_number: int
    """

    if test_number == 0:
        raise PlantError("The tomato plant is wilting!")
    elif test_number == 1:
        raise WaterError("Not enough water in the tank!")


def ft_custom_error() -> None:

    """
    This function catches the custom errors and display the
    according error-message

    Returns:
        None
    """

    print(HEADER)

    for test_number in range(2):

        try:
            custom_errors_test(test_number)

        except PlantError as e:
            print(f"Inspecting the Tomatoes...\n"
                  f"Caught {e.__class__.__name__}: {e}\n")
        except WaterError as e:
            print(f"Checking if the Tank is full...\n"
                  f"Caught {e.__class__.__name__}: {e}\n")

    print(f"{ALL_ERROR_CAUGHT}...")

    for test_number in range(2):

        try:
            custom_errors_test(test_number)

        except GardenError as e:
            print("Caught GardenError:", e)

    print(PROGRAM_END)


# >>>>Runs the Code<<<<

if __name__ == "__main__":

    # This line runs the block of if we call the program DIRECTLY,
    # but will not, if it is imported.

    ft_custom_error()
