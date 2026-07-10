class Plant:

    def __init__(self, name: str, current_height: float,
                 growth_rate: float, current_age: int) -> None:
        self.name = name
        self._current_height = 0
        self.set_current_height(current_height)
        self._growth_rate = growth_rate
        self._current_age = 0
        self.set_current_age(current_age)

    def __str__(self) -> str:
        return (
            f"Plant created: {self.name.capitalize()}: "
            f"{self._current_height}cm, "
            f"{self._current_age} days old"
        )

    def show(self) -> None:
        print(self)

    def grow(self) -> None:
        self._current_height = round(self._current_height +
                                     self._growth_rate, 1)

    def age(self) -> None:
        self._current_age += 1

    def get_current_height(self) -> float:
        return self._current_height

    def set_current_height(self, current_height: float) -> None:
        if current_height >= 0:
            self._current_height = current_height
        else:
            print(f"\n{self.name.capitalize()}: "
                  f"Error, height can't be negative")
            print("Height update rejected")

    def get_current_age(self) -> int:
        return self._current_age

    def set_current_age(self, current_age: int) -> None:
        if current_age >= 0:
            self._current_age = current_age
        else:
            print(f"\n{self.name.capitalize()}: Error, age can't be negative")
            print("Age update rejected\n")


def ft_garden_security() -> None:
    plant1 = Plant("himawari", 175.5, 2.4, 100)
    print("=== Garden Security Systems ===")
    plant1.show()
    plant1.set_current_height(199.5)
    print(f"\nHeight updated: {plant1.get_current_height()}cm")
    plant1.set_current_age(110)
    print(f"Age updated: {plant1.get_current_age()}\n")
    plant1.set_current_height(-42.0)
    plant1.set_current_age(-42)
    print(f"Current state: {plant1.name.capitalize()}: "
          f"{plant1.get_current_height()}cm, "
          f"{plant1.get_current_age()} days old")


if __name__ == "__main__":
    ft_garden_security()
