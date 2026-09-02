def ft_plant_age() -> None:
    entry = input("Enter Plant age in days: ")
    if int(entry) > 60:
        print("Plant is ready to harvest!")
    else:
        print("Plant needs more time to grow.")
