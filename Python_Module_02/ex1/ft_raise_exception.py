#!/usr/bin/env python3

# >>>>Global Constants<<<<

HEADER: str = "=== Garden Temperature Checker ===\n"
TEMP_INPUT: str = "Input data is"
TEMP_DISPLAY: str = "Temperature is now"
PROGRAM_END: str = "All tests completed - program didn't crash!"
ERROR_MESSAGE: str = "Caught input_temperature error:"
TEMP_MIN: int = 0
TEMP_MAX: int = 40


def input_temperature(temp_str: str) -> int:

    """
    This function converts str into an int, and also raise if
    temp_int is < 0 or > 40

    Args:
        temp_str: the str we want to convert

    Returns:
        the int conversion of the str

    Raises:
        a ValueError message if int(temp_str) get invalid literal for
        int() with base 10
        a ValueError message if temp_int isn't >= 0 or <= 40
    """

    temp_int: int = int(temp_str)
    if temp_int < TEMP_MIN:
        raise ValueError(f"{temp_str}°C is too cold "
                         f"for plants (min {TEMP_MIN}°C)"
                         )
    if temp_int > TEMP_MAX:
        raise ValueError(f"{temp_str}°C is too hot "
                         f"for plants (max {TEMP_MAX}°C)"
                         )
    return temp_int


def test_temperature() -> None:

    """
    A test function that catches error depending if
    [input_temperature(temp_str: str) -> int:] raises

    Returns:
        None
    """

    values_to_test: list[str] = ["14", "Bonjour", "100", "-50"]

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
