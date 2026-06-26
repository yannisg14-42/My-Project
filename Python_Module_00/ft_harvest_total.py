def ft_harvest_total() -> None:
    first_harvest = input("Day 1 harvest: ")
    second_harvest = input("Day 2 harvest: ")
    third_harvest = input("Day 3 harvest: ")
    print("Total harvest:", int(first_harvest) + int(second_harvest)
          + int(third_harvest))
