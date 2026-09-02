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
        self._stats = Plant.Statistics()

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
        self._stats.count_show()

    def grow(self) -> None:
        self._current_height = round(self._current_height +
                                     self._growth_rate, 1)
        self._stats.count_grow()

    def age(self) -> None:
        self._current_age += 1
        self._stats.count_age()

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

    class Statistics:

        def __init__(self) -> None:
            self._grow_count = 0
            self._age_count = 0
            self._show_count = 0

        def count_grow(self) -> None:
            self._grow_count += 1

        def count_age(self) -> None:
            self._age_count += 1

        def count_show(self) -> None:
            self._show_count += 1

        def __str__(self) -> str:
            return (f"Stats: {self._grow_count} grow, "
                    f"{self._age_count} age, "
                    f"{self._show_count} show")

        def show_stats(self) -> None:
            print(self)


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


class Seed(Flower):

    def __init__(self, name: str, current_height: float, growth_rate: float,
                 current_age: int, color: str) -> None:
        super().__init__(name, current_height, growth_rate, current_age, color)
        self._seed_count = 0

    def show(self) -> None:
        super().show()
        print(f" Seeds: {self._seed_count}")

    def bloom(self) -> None:
        super().bloom()
        self._seed_count = 42


class Tree(Plant):

    def __init__(self, name: str, current_height: float, growth_rate: float,
                 current_age: int, trunk_diameter: float) -> None:
        super().__init__(name, current_height, growth_rate, current_age)
        self._trunk_diameter = trunk_diameter
        self._stats: "Tree.TreeStatistics" = Tree.TreeStatistics()

    def show(self) -> None:
        super().show()
        print(f" Trunk diameter: {self._trunk_diameter}cm")

    def produce_shade(self) -> None:
        print(f"Tree {self.name.capitalize()} now produces a shade of "
              f"{self._current_height}cm long and "
              f"{self._trunk_diameter}cm wide.")
        self._stats.count_shade()

    class TreeStatistics(Plant.Statistics):

        def __init__(self) -> None:
            super().__init__()
            self._shade_count = 0

        def count_shade(self) -> None:
            self._shade_count += 1

        def __str__(self) -> str:
            return super().__str__() + f"\n {self._shade_count} shade"


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


def display_statistics(plant: Plant) -> None:
    print(f"[statistics for {plant.name.capitalize()}]")
    plant._stats.show_stats()


def ft_garden_analytics() -> None:
    flower1 = Flower("bara", 24.5, 2.1, 30, "blue")
    age1 = 30
    age2 = 400
    print("=== Garden statistics ===")

    print("=== Check year-old")
    print(f"Is {age1} days more than a year? -> "
          f"{Plant.is_older_than_a_year(age1)}")
    print(f"Is {age2} days more than a year? -> "
          f"{Plant.is_older_than_a_year(age2)}")

    print("\n=== Flower")
    flower1.show()
    display_statistics(flower1)
    print(f"[asking for {flower1.name} to grow and bloom]")
    flower1.grow()
    flower1.bloom()
    flower1.show()
    display_statistics(flower1)

    tree1 = Tree("sakura", 414.4, 0.2, 14610, 34.4)
    print("\n=== Tree")
    tree1.show()
    display_statistics(tree1)
    print(f"[asking the {tree1.name} to produce shade]")
    tree1.produce_shade()
    display_statistics(tree1)

    seed1 = Seed("himawari", 175.5, 2.4, 100, "yellow")
    print("\n=== Seed")
    seed1.show()
    print(f"[make {seed1.name} grow, age and bloom]")
    seed1.grow()
    seed1.age()
    seed1.bloom()
    seed1.show()
    display_statistics(seed1)

    print("\n=== Anonymous")
    anonymous = Plant.create_anonymous()
    anonymous.show()
    display_statistics(anonymous)


if __name__ == "__main__":
    ft_garden_analytics()
