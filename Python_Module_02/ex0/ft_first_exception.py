#!/usr/bin/env python3

# >>>>Global Constants<<<<

HEADER: str = "=== Garden Temperature ===\n"
TEMP_INPUT: str = "Input data is"
TEMP_DISPLAY: str = "Temperature is now"
PROGRAM_END: str = "All tests completed - program didn't crash!"
ERROR_MESSAGE: str = "Caught input_temperature error:"


def input_temperature(temp_str: str) -> int:

    """
    Simple function converting a str into an int

    Args:
        temp_str: the str we want to convert

    Returns:
        the int conversion of the str

    Raises:
        a ValueError message if int(temp_str) get invalid literal for
        in() with base 10
    """

    return int(temp_str)


def test_temperature() -> None:

    """
    A test function that catches error depending if
    [input_temperature(temp_str: str) -> int:] raises

    Returns:
        None
    """

    values_to_test: list[str] = ["14", "Bonjour"]

    print(HEADER)

    for temp_str in values_to_test:
        try:
            print(f"{TEMP_INPUT} '{temp_str}'")
            print(f"{TEMP_DISPLAY} {input_temperature(temp_str)}°C\n")

        except ValueError as e:
            print(f"{ERROR_MESSAGE} {e}\n")

    print(PROGRAM_END)


# >>>>Runs the Code<<<<

if __name__ == "__main__":

    # This line runs the block of if we call the programm DIRECTLY,
    # but will not, if it is imported.

    test_temperature()
