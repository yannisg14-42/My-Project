#!/usr/bin/env python3

import sys

# ---- global constants
HEADER: str = "=== Inventory System Analysis ==="
USAGE: str = "Usage: python3 ft_inventory_system.py <item_name>:<quantity> ..."
TOTAL: str = "Total quantity of the"


# ---- Code
def main() -> None:
    """
    Build and analyse a game inventory from command-line arguments.

    Each argument must follow the format <item_name>:<quantity>.
    Arguments are checked one by one, and rejected with a message when:
        - they do not split into exactly two pieces on ':',
        - the quantity cannot be converted to int,
        - the quantity is zero or negative,
        - the item name is already in the inventory (first one wins).
    Valid arguments are stored in a dict, item name -> quantity.

    If no valid item remains, a message is printed and the function
    returns early. Otherwise it prints:
        - the inventory and the list of item names,
        - the total quantity and each item's share in percent,
        - the most and least abundant items (the first item on the
          command line wins a tie, using strict comparisons),
        - the inventory again after adding a new item with update().
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

        least: int = 0

        most: int = 0

        i = 1

        while i < items_total:
            if items_quantity[i] < items_quantity[least]:
                least = i

            if items_quantity[i] > items_quantity[most]:
                most = i

            i += 1

        most_item: str = items_list[most]
        least_item: str = items_list[least]

        most_quantity: int = items_quantity[most]
        least_quantity: int = items_quantity[least]

        print(f"Item most abundant: {most_item} with quantity {most_quantity}")

        print(
              f"Item least abundant: {least_item} "
              f"with quantity {least_quantity}"
        )

        dictionary.update({"magic_item": 7, "sword": 4})

        print(f"Updated inventory: {dictionary}")


# ---- Run the code
if __name__ == "__main__":
    # This line runs the block of if we call the program DIRECTLY,
    # but will not, if it is imported.

    main()
