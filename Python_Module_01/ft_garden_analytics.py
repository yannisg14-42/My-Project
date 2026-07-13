# Parent Class Plant with all Atributes
class Plant:

    def __init__(self, name: str, current_height: float,
                 growth_rate: float, current_age: int) -> None:
        self.name = name
        self._growth_rate = growth_rate
        # This how we Validate the protected value
        # To avoid Data corruption
        self._current_height = 0.0
        self.set_current_height(current_height)
        self._current_age = 0
        self.set_current_age(current_age)

    @staticmethod
    def is_older_than_a_year(age: int) -> bool:
        return age > 365

    @classmethod
    def create_anonymous(cls) -> "Plant":
        return cls("Unknown plant", 0.0, 0.0, 0)

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


# Child Classes "Flower", "Tree" and "Vegetables"
# They inherit the Atributes and Methods of Parent Class "Plant"
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


class Vegetable(Plant):

    def __init__(self, name: str, current_height: float, growth_rate: float,
                 current_age: int, harvest_season: str,
                 nutritional_value: int) -> None:
        super().__init__(name, current_height, growth_rate, current_age)
        self._harvest_season = harvest_season
        self._nutritional_value = nutritional_value

    def show(self) -> None:
        super().show()
        print(f" Harvest season: {self._harvest_season.capitalize()}")
        print(f" Nutritional value: {self._nutritional_value}")

    def grow(self) -> None:
        super().grow()
        self._nutritional_value += 1

    def age(self) -> None:
        super().age()


def ft_garden_analytics() -> None:
    flower1 = Flower("bara", 24.5, 2.1, 30, "blue")
    age1 = 30
    age2 = 400
    print("=== Garden statistics ===")
    print("=== Check year-old")
    print(f"Is {age1} days more than a year? -> {Plant.is_older_than_a_year(age1)}")
    print(f"Is {age2} days more than a year? -> {Plant.is_older_than_a_year(age2)}")
    print("\n=== Flower")
    flower1.show()
    print(f"[asking the {flower1.name} to bloom]")
    flower1.bloom()
    flower1.show()

    tree1 = Tree("sakura", 414.4, 0.2, 14610, 34.4)
    print("\n=== Tree")
    tree1.show()
    print(f"[asking the {tree1.name} to produce shade]")
    tree1.produce_shade()

    vegetable1 = Vegetable("tomato", 5.0, 2.1, 10, "april", 0)
    days_to_simulate: int = 20
    print("\n=== Vegetable")
    vegetable1.show()
    print(f"[make {vegetable1.name} grow and age for {days_to_simulate} days]")
    for days in range(days_to_simulate):
        vegetable1.grow()
        vegetable1.age()
    vegetable1.show()


    print("\n=== Anonymous")
    anonymous = Plant.create_anonymous()
    anonymous.show()
    

if __name__ == "__main__":
    ft_garden_analytics()
