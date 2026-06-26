def ft_count_harvest_iterative() -> None:
    countdown = input("Days until harvest: ")
    for day in range(1, int(countdown) + 1):
        print("Day", day)
    print("Harvest time!")
