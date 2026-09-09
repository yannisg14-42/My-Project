#!/usr/bin/env python3

# >>>>Global Constants<<<<

HEADER: str = "=== Custom Garden Errors Demo ===\n"
PROGRAM_END: str = "All custom error types work correctly!!"


class GardenError(Exception):

    """
    The main class of our custom errors, that itself,
    iherit from Exception

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
    """

    if test_number == 0:
        raise PlantError("The tomato plant is wilting!")
    elif test_number == 1:
        raise WaterError("Not enough water in the tank!")
    elif test_number == 2:
        raise GardenError()
def ft_custom_error() -> None:

    """
    """

    print(HEADER)

    for test_number in range(2):

        try:
            custom_errors_test(test_number)
            print("All good!")

        except (PlantError, WaterError, GardenError) as e:
            print(f"Testing {e.__class__.__name__}...\n"
                  f"Caught {e.__class__.__name__}: {e}\n")
        

# >>>>Runs the Code<<<<

if __name__ == "__main__":

    # This line runs the block of if we call the programm DIRECTLY,
    # but will not, if it is imported.

    ft_custom_error()