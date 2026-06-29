class Plant:

    def __init__(self, name: str, height: int, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age

    def __str__(self) -> str:
        return (
            f"{self.name.capitalize()}: "
            f"{self.height}cm, "
            f"{self.age} days old"
        )

    def show(self) -> None:
        print(self)


def ft_garden_data() -> None:
    plant1 = Plant("himawari", 300, 100)
    plant2 = Plant("ume", 400, 7300)
    plant3 = Plant("suisen", 50, 1825)
    print("=== Garden Plant Registry ===")
    plant1.show()
    plant2.show()
    plant3.show()


if __name__ == "__main__":
    ft_garden_data()
