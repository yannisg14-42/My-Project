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
            f"{self.name.capitalize()}: "
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


class Flower(Plant):

    def __init__(self, name: str, current_height: float, growth_rate: float,
                 current_age: int, color: str) -> None:
        super().__init__(name, current_height, growth_rate, current_age)
        self._color = color
        self._has_bloomed = False

    def show(self) -> None:
        super().show()
        print(f" Color: {self._color}")
        if self._has_bloomed:
            print(f" {self.name.capitalize()} is blooming beautifully!")
        else:
            print(f" {self.name.capitalize()} has not bloomed yet")

    def bloom(self) -> None:
        self._has_bloomed = True


class Tree(Plant):

    def __init__(self, name: str, current_height: float, growth_rate: float,
                 current_age: int, trunk_diameter: float) -> None:
        super().__init__(name, current_height, growth_rate, current_age)
        self._trunk_diameter = trunk_diameter

    def show(self) -> None:
        super().show()
        print(f" Trunk diameter: {self._trunk_diameter}cm")

    def produce_shade(self) -> None:
        print(f"Tree {self.name.capitalize()} now produces a shade of "
              f"{self._current_height}cm long and "
              f"{self._trunk_diameter}cm wide.")


def ft_plant_types() -> None:
    flower1 = Flower("bara", 24.5, 2.1, 30, "blue")
    print("=== Garden Plant Types ===")
    print("=== Flower")
    flower1.show()
    print("[asking the rose to bloom]")
    flower1.bloom()
    flower1.show()
    tree1 = Tree("sakura", 414.4, 0.2, 14610, 34.4)
    print("\n=== Tree")
    tree1.show()
    print("[asking the sakura to produce shade]")
    tree1.produce_shade()


if __name__ == "__main__":
    ft_plant_types()
