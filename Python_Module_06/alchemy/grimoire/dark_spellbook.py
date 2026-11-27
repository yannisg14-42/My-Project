from .dark_validator import validate_ingredients


# |-- CODE --|
def dark_spell_allowed_ingredients() -> list[str]:

    return ["bats", "frogs", "arsenic", "eyeball"]


def dark_spell_record(spell_name: str, ingredients: str) -> str:

    ingredients_validation: str = validate_ingredients(ingredients)

    if ingredients_validation.endswith("- VALID"):
        return (f"Spell recorded: {spell_name} ({ingredients_validation})")

    if ingredients_validation.endswith("- INVALID"):
        return (f"Spell rejected: {spell_name} ({ingredients_validation})")

    return ("Missing validator keyword!")
