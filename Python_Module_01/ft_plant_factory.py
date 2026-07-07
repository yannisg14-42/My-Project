class Plant:

    def __init__(self, name: str, current_height: float,
                 growth_rate: float, current_age: int) -> None:
        self.name = name
        self.current_height = current_height
        self.current_age = current_age
        self.growth_rate = growth_rate

    def __str__(self) -> str:
        return (
            f"Created: {self.name.capitalize()}: "
            f"{self.current_height}cm, "
            f"{self.current_age} days old"
        )

    def show(self) -> None:
        print(self)

    def grow(self) -> None:
        self.current_height = round(self.current_height + self.growth_rate, 1)

    def age(self) -> None:
        self.current_age = self.current_age + 1

def ft_plant_factory() -> None:
    plant1 = Plant("sakura", 414.4, 0.2, 14610)
    plant2 = Plant("ume",777.1, 0.18, 36524)
    plant3 = Plant("himawari", 175.5, 2.4, 100)
    plant4 = Plant("tanpopo", 35.0, 2.0, 1461)
    plant5 = Plant("suisen", 56.6, 1.9, 49)
    print("=== Plant Factory Output ===")
    plant1.show()
    plant2.show()
    plant3.show()
    plant4.show()
    plant5.show()


if __name__ == "__main__":
    ft_plant_factory()