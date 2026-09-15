#!/usr/bin/env python3

import sys


# >>>Global Constant<<<

HEADER: str = "=== Command Quest ==="
PROGRAM: str = "Program name:"
NO_ARGS: str = "No arguments provided!"
TOTAL_ARGS: str = "Total arguments:"
ARGS_AFTER_PROGRAM_NAME: str = "Arguments received:"


def ft_command_quest() -> None:

    """
    By importing sys, I wrote a program, that always display the program's
    name, the number of arguments after program's name, the str
    representation of those arguments, and the total of arguments
    program's name included. Argument are provided in the terminal
    at run time.

    Returns
        None
    """

    print(HEADER)

    if len(sys.argv) == 1:

        print(f"{PROGRAM} {sys.argv[0]}\n{NO_ARGS}")
        print(f"{TOTAL_ARGS} {len(sys.argv)}")

    else:

        len_of_received_args: int = len(sys.argv) - 1

        print(f"{PROGRAM} {sys.argv[0]}")
        print(f"{ARGS_AFTER_PROGRAM_NAME} {len_of_received_args}")

        argv_index: int = 1

        while argv_index < len(sys.argv):
            print(f"Argument {argv_index}: {sys.argv[argv_index]}")
            argv_index += 1

        print(f"{TOTAL_ARGS} {len(sys.argv)}")


# >>>>Runs the Code<<<<

if __name__ == "__main__":

    # This line runs the block of if we call the program DIRECTLY,
    # but will not, if it is imported.

    ft_command_quest()
