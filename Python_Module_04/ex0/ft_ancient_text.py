#!/usr/bin/env python3


import sys
import typing

# ---- Global Constants
BANNER: str = "=== Cyber Archives Recovery ==="
USAGE: str = "Usage: ./ft_ancient_text.py <file>"
ERROR: str = "Error opening file"
GRAB: str = "Accessing file"
EDGE_OF_TEXT: str = "---"


def main() -> None:

    """
    A function opens a file, read, print its content and close it.
    If we have more than 1 file or just the program's name, it displays
    a usage message.
    If the file we are trying to open is faulty, open() raises, then 'except'
    catches the error and display an error message.
    """

    if len(sys.argv) != 2:
        print(USAGE)

    else:
        print(BANNER)

        print(f"{GRAB} '{sys.argv[1]}'")

        try:
            opened_file: typing.IO[str] = open(sys.argv[1])

            content: str = opened_file.read()

            print(EDGE_OF_TEXT)

            print(content)

            print(EDGE_OF_TEXT)

            opened_file.close()

            print(f"File '{sys.argv[1]}' closed.")

        except OSError as e:
            print(f"{ERROR} '{sys.argv[1]}': {e}")


# ---- Run the Code
if __name__ == "__main__":

    # This line runs the above block of code, IF we call the program DIRECTLY!
    # If it is an import, then the code won't run.

    main()
