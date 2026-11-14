#!/usr/bin/env python3

import sys

# ---- Global constants
HEADER: str = "=== Inventory System Analysis ==="
USAGE: str = "Usage: python3 ft_inventory_system.py <item_name>:<quantity> ..."
TOTAL: str = "Total quantity of the"


# ---- Code
def main() -> None:
    """
    A program
    """

    print(HEADER)

    if len(sys.argv) == 1:
        print(USAGE)

    else:
        dictionary: dict[str, int] = {}

        i: int = 1

        # ---- Error handling and dict creation
        while i < len(sys.argv):
            keys_and_values: list[str] = sys.argv[i].split(':')

            key: str = keys_and_values[0]

            if len(keys_and_values) != 2:
                print(f"Error - invalid parameter '{sys.argv[i]}'")
                i += 1
                continue

            try:
                value: int = int(keys_and_values[1])

            except ValueError as v_e:
                print(f"Quantity error for '{key}': {v_e}")
                i += 1
                continue

            if value <= 0:
                print(f"Incorrect value given for this item: {key}")
                i += 1
                continue

            if key in dictionary:
                print(f"Redundant item '{key}' - discarding")
                i += 1
                continue

            dictionary.update({key: value})
            i += 1

        if not dictionary:
            print("No data to work with!")
            return

        print(f"Got inventory: {dictionary}")

        items_list: list[str] = list(dictionary.keys())

        print(f"Item list: {items_list}")

        items_quantity: list[int] = list(dictionary.values())

        items_total: int = len(items_list)

        items_sum: int = sum(items_quantity)

        print(f"{TOTAL} {items_total} items: {items_sum}")

        i = 0

        # ---- Percentage of all items
        while i < items_total:
            item_percentage: float = (
                round(((items_quantity[i] * 100) / items_sum), 1)
            )

            print(f"Item {items_list[i]} represents {item_percentage}%")
            i += 1

        least: int = items_quantity[0]

        most: int = 0

        i = 0

        while i < items_total:
            if items_quantity[i] <= least:
                least = items_quantity[i]

            if items_quantity[i] >= most:
                most = items_quantity[i]
            i += 1

        print(f"Item most abundant: with quantity {most}")

        print(f"Item least abundant: with quantity {least}")

        dictionary.update({"magic_item": 1})

        print(f"Updated inventory: {dictionary}")


# ---- Run the code
if __name__ == "__main__":
    # This line runs the block of if we call the program DIRECTLY,
    # but will not, if it is imported.

    main()
