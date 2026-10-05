#!/usr/bin/env python3


import sys
import typing

# ---- Global Constants
BANNER: str = "=== Cyber Archives Recovery & Preservation ==="
USAGE: str = "Usage: ./ft_stream_management.py <file>"
ERROR_OPENING: str = "Error opening file"
ERROR_DECODING: str = "Error decoding file"
ERROR_WRITING: str = "Error writing in file"
GRAB: str = "Accessing file"
MODIFYING: str = "\nTransform data:"
EDGE_OF_TEXT: str = "---"
SAVE_MESSAGE: str = "Enter a new file name (or empty): "
NOT_SAVING: str = "Not saving data."
NOT_SAVED: str = "Data not saved."
SAVING: str = "Saving data to"
SAVED: str = "Data saved in file"


# ---- Code's Logic
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
    Afterward, we modify the content of our file to put a '#' at the end of
    each line.
    We then modify our input() with sys.stdout.writ() to display a message and
    return prompt. On the prompt if we enter nothing or only whitspaces,
    a simple message is displayed.
    Otherwise if we write a valid str on sys.stdin, our modified content
    is saved into a file with the str as file's name in 2 steps.
    First it try to open the new file in 'w' mode; if it fails, open() raises,
    'except' catches and we display an error message on sys.stderr.
    Secondly we try to write the new content in the new file; if it fails,
    .write() raises, 'except' catches, and display an error message on
    sys.stderr.
    In the 'finally' block the new file is always closed.
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
            sys.stderr.write(f"[STDERR] {ERROR_OPENING} "
                             f"'{sys.argv[1]}': {e}\n")
            return

        # ---- .read() Guard
        try:
            content: str = opened_file.read()

        except UnicodeError as e:
            sys.stderr.write(f"[STDERR] {ERROR_DECODING} "
                             f"'{sys.argv[1]}': {e}\n")
            return

        else:
            print(f"{EDGE_OF_TEXT}\n")

            print(content)

            print(EDGE_OF_TEXT)

        finally:
            opened_file.close()

            print(f"File '{sys.argv[1]}' closed.")

        # ---- File's modification
        lines: list[str] = content.splitlines()

        new_lines: list[str] = [line + '#' for line in lines]

        new_text: str = '\n'.join(new_lines)

        print(MODIFYING)

        print(f"{EDGE_OF_TEXT}\n")

        print(new_text)

        print(f"\n{EDGE_OF_TEXT}")

        # ---- Where to save new content input
        sys.stdout.write(SAVE_MESSAGE)

        sys.stdout.flush()

        new_file: str = sys.stdin.readline()

        cleaned_new_file: str = new_file.removesuffix("\n")

        only_spaces: bool = cleaned_new_file.isspace()

        if not cleaned_new_file or only_spaces:
            print(NOT_SAVING)

        else:
            print(f"{SAVING} '{cleaned_new_file}'")

            # ---- open() Guard
            try:
                save_dest: typing.IO[str] = open(cleaned_new_file, 'w')

            except OSError as e:
                sys.stderr.write(f"[STDERR] {ERROR_OPENING} "
                                 f"'{cleaned_new_file}': {e}\n")
                print(NOT_SAVED)
                return

            # ---- .write() Guard
            try:
                save_dest.write(new_text)

                save_dest.write("\n")

            except OSError as e:
                sys.stderr.write(f"[STDERR] {ERROR_WRITING} "
                                 f"'{cleaned_new_file}': {e}\n")
                print(NOT_SAVED)

            else:
                print(f"{SAVED} '{cleaned_new_file}'.")

            finally:
                save_dest.close()

                print(f"File '{cleaned_new_file}' closed.")


# ---- Run the Code
if __name__ == "__main__":

    # This line runs the above block of code, IF we call the program DIRECTLY!
    # If it is an import, then the code won't run.

    main()
