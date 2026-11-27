# |-- CODE --|
def light_spell_allowed_ingredients() -> list[str]:

    return ["air", "earth", "fire", "water"]


def light_spell_record(spell_name: str, ingredients: str) -> str:

    from alchemy.grimoire.light_validator import validate_ingredients

    ingredients_validation: str = validate_ingredients(ingredients)

    if ingredients_validation.endswith("- VALID"):
        return (f"Spell recorded: {spell_name} ({ingredients_validation})")

    if ingredients_validation.endswith("- INVALID"):
        return (f"Spell rejected: {spell_name} ({ingredients_validation})")

    return ("Missing validator keyword!")
