#!/usr/bin/env python3

# ---- Global Constants
BANNER: str = "=== Cyber Archives Security ==="
READ_NONEXISTENT: str = ("Using 'secure_archive' to read "
                         "from a nonexistent file:"
                         )
READ_INACCESSIBLE: str = ("Using 'secure_archive' to read "
                          "from an inaccessible file:"
                          )
READ_SUCCESS: str = "Using 'secure_archive' to read from a regular file:"
WRITE_SUCCESS: str = ("Using 'secure_archive' to write "
                      "previous content to a new file:"
                      )
WRITE_SUCCESS_MESSAGE: str = "Content successfully written to file"
EVOLVING: str = "Using 'secure_archive' to evolve into a transcendent being"
WRONG_FILE_ACTION: str = ("This function expect as file_action either "
                          "'read' or 'write'"
                          )


# ---- Code's Logic
def secure_archive(file_name: str,
                   file_action: str = "read",
                   file_content: str = ""
                   ) -> tuple[bool, str]:
    """
    A function that take 1 mandatory argument i.e the file's name,
    and 2 optional arguments that are the mode and the file's
    content.
    The function has 2 logics that are reading or writing.
    If file_action is 'read', then we use with to open in -r mode
    then read the content; in case of failure read() raises and except
    catches.
    If file_action is 'write', then we use with to open in -w mode
    then write the content in a new fiel; in case of failure .write()
    raises and except catches.

    Args:
        file_name: our mandatory argument that is the file we read or
        write into
        file_action: an optional str argument telling us if we want to
        use read or write into our fle_name
        file_content: an optional  str argument giving us the content we
        write in the file_name

    Returns:
        a tuple[bool, str]; the bool tell use if the operation was
        successful or not, and the str give us more information abut what
        worked or went wrong.

    """

    # ---- read() Logic and Guard
    if file_action == "read":
        try:
            with open(file_name, "r") as file:
                content: str = file.read()

        except OSError as e:
            return (False, str(e))

        except UnicodeError as e:
            return (False, str(e))

        else:
            return (True, content)

    # ---- .write() Logic and Guard
    elif file_action == "write":
        try:
            with open(file_name, "w") as file:
                file.write(file_content)

        except OSError as e:
            return (False, str(e))

        else:
            return (True, WRITE_SUCCESS_MESSAGE)

    # ---- no read() nor .write()
    else:
        return (False, WRONG_FILE_ACTION)


# ---- Run the Code
if __name__ == "__main__":

    # This line runs the above block of code, IF we call the program DIRECTLY!
    # If it is an import, then the code won't run.

    print(BANNER)

    print()

    print(READ_NONEXISTENT)
    result: tuple[bool, str] = secure_archive("42")
    print(result)

    print()

    print(READ_INACCESSIBLE)
    result = secure_archive("etc/master.passwd")
    print(result)

    print()

    print(READ_SUCCESS)
    result = secure_archive("ancient_fragment.txt")
    print(result)

    print()

    print(WRITE_SUCCESS)
    result = secure_archive("new_file.txt", "write", result[1])
    print(result)

    print()

    print(EVOLVING)
    result = secure_archive("ancient_fragment.txt", "evolve")
    print(result)
