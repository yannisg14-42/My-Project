#!/usr/bin/env python3

# >>>>Global Constants<<<<

HEADER: str = "=== Garden Error Types Demo ==="
TEST_PROCESS_MESSAGE: str = "Testing operation"
OPERATION_SUCCESS: str = "Operation completed successfully"
PROGRAM_END: str = "\nAll error types tested successfully!"


def garden_operations(operation_number: int) -> None:

    """
    A function that execute different type of faulty operations
    depending on operation_number: int

    Args:
        operation_number: an int that execute a type of faulty operation

    Returns:
        None
    """

    if operation_number == 0:
        int("Aphelios")
    elif operation_number == 1:
        4 / 0
    elif operation_number == 2:
        open("/non/existent/file")
    elif operation_number == 3:
        14 + "WAS!"


def test_error_types() -> None:

    """
    This function catches the errors, and print an error message
    depending of the type of error. It does it with only one try: block

    Returns:
        None
    """

    print(HEADER)

    for operation_number in range(5):

        print(f"{TEST_PROCESS_MESSAGE} {operation_number}...")

        try:
            garden_operations(operation_number)
            print(OPERATION_SUCCESS)

        except (ValueError, ZeroDivisionError,
                FileNotFoundError, TypeError) as e:
            print(f"Caught {e.__class__.__name__}: {e}")

    print(PROGRAM_END)


# >>>>Runs the Code<<<<

if __name__ == "__main__":

    # This line runs the block of if we call the program DIRECTLY,
    # but will not, if it is imported.

    test_error_types()
