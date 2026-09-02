def ft_water_reminder() -> None:
    reminder = input("Days since last watering: ")
    if int(reminder) > 2:
        print("Water the plants!")
    else:
        print("Plants are fine")
