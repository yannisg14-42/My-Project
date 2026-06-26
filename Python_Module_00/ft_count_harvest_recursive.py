def ft_recursion(day: int) -> None:
    if day > 1:
        ft_recursion(day - 1)
    print("Day", day)


def ft_count_harvest_recursive() -> None:
    countdown = input("Days until harvest: ")
    ft_recursion(int(countdown))
    print("Harvest time!")
