class Plant:

    def __init__(self, name: str, current_height: float,
                 growth_rate: float, current_age: int) -> None:
        self.name = name
        self.current_height = current_height
        self.current_age = current_age
        self.growth_rate = growth_rate

    def __str__(self) -> str:
        return (
            f"{self.name.capitalize()}: "
            f"{self.current_height}cm, "
            f"{self.current_age} days old"
        )

    def show(self) -> None:
        print(self)

    def grow(self) -> None:
        self.current_height = round(self.current_height + self.growth_rate, 1)

    def age(self) -> None:
        self.current_age = self.current_age + 1


def ft_plant_growth() -> None:
    plant1 = Plant("himawari", 175.5, 2.4, 100)
    initial_height = plant1.current_height
    print("=== Garden Plant Growth ===")
    plant1.show()
    for days in range(1, 8):
        plant1.grow()
        plant1.age()
        print(f"=== Day {days} ===")
        plant1.show()
    total_growth = round(plant1.current_height - initial_height, 1)
    print(f"Growth this week: {total_growth}cm")


if __name__ == "__main__":
    ft_plant_growth()
