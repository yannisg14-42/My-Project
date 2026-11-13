#!/usr/bin/env python3

import sys

# ---- Global constants
HEADER: str = "=== Inventory System Analysis ==="
USAGE: str = "Usage: python3 ft_inventory_system.py <item_name>:<quantity> ..."
INVENTORY: str = "Got inventory:"
INVALID: str = "Error - invalid parameter"

# ---- Code
def main() -> None:
    """
    A program
    """

    print(HEADER)

    if len(sys.argv) == 1:
        print(USAGE)

    else:
        dictionary: dict = {}

        i: int = 1

        while i < len(sys.argv):
            keys_and_values: list[str] = sys.argv[i].split(':')
            print('DEBUG', keys_and_values)
            if len(keys_and_values) != 2:
                 print(f"{INVALID} '{keys_and_values[0]}'")
            i += 1

        print(f"{INVENTORY} {dictionary}")


# ---- Run the code
if __name__ == "__main__":
    # This line runs the block of if we call the program DIRECTLY,
    # but will not, if it is imported.

    main()
