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


# ---- Code's Logic
def secure_archive(file_name: str,
                   file_action: str = "",
                   file_content: str = ""
                   ) -> tuple[bool, str]:
    """
    A function that take 1 mandatory argument i.e the file's name,
    and 2 optional arguments that are the mode and the file's
    content.

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


# ---- Run the Code
if __name__ == "__main__":

    # This line runs the above block of code, IF we call the program DIRECTLY!
    # If it is an import, then the code won't run.

    print(BANNER)

    print()

    print(READ_NONEXISTENT)
    result: tuple[bool, str] = secure_archive("yoyo", "write")
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
