#!/usr/bin/env python3


import sys
import typing

# ---- Global Constants
BANNER: str = "=== Cyber Archives Recovery ==="
USAGE: str = "Usage: ./ft_ancient_text.py <file>"
ERROR_OPENING: str = "Error opening file"
ERROR_DECODING: str = "Error decoding file"
GRAB: str = "Accessing file"
EDGE_OF_TEXT: str = "---"


# ---- Code Logic
def main() -> None:

    """
    A program that opens a file, read it, print its content and close it.
    If we have more than 1 file or just the program's name, it displays
    a usage message.
    If the file we are trying to open is faulty, open() raises, then 'except'
    catches the error and display an error message, and we exit the program
    directly, since there is nothing to close.
    If we can open the file but cannot read it, then read() raises, 'except'
    catches the error, display an error message, and we close the file at
    the end.
    """

    if len(sys.argv) != 2:
        print(USAGE)

    else:
        print(BANNER)

        print(f"{GRAB} '{sys.argv[1]}'")

        # ---- open() Guard
        try:
            opened_file: typing.IO[str] = open(sys.argv[1])

        except OSError as e:
            print(f"{ERROR_OPENING} '{sys.argv[1]}': {e}")

            return

        # ---- read() Guard
        try:
            content: str = opened_file.read()

            print(EDGE_OF_TEXT)

            print(content)

            print(EDGE_OF_TEXT)

        except UnicodeError as e:
            print(f"{ERROR_DECODING} '{sys.argv[1]}': {e}")

        opened_file.close()

        print(f"File '{sys.argv[1]}' closed.")


# ---- Run the Code
if __name__ == "__main__":

    # This line runs the above block of code, IF we call the program DIRECTLY!
    # If it is an import, then the code won't run.

    main()
