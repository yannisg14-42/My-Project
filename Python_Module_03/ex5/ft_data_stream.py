#!/usr/bin/env python3

import random
from typing import Generator

# ---- Global constants
HEADER: str = "=== Game Data Stream Processor ==="
PLAYERS: list[str] = [
        "Minato", "Haruto", "Sakura", "Ren", "Aoi", "Himari", "Riku"
]
ACTIONS: list[str] = [
        "play", "eat", "learn", "sleep", "jump", "write", "climb",
        "grab", "laugh", "use", "move", "swim", "watch", "talk",
        "shoot", "punch", "buy", "sell", "build", "drink", "kick"
]


# ---- Code
def gen_event() -> Generator[tuple[str, str], None, None]:
    """
    A function, that becomes a Generator after the use of the "yield"
    keyword.

    It pick a random member from a list of PLAYERS and a list of
    ACTIONS, then form a tuple() with those two elements and yield it.
    """

    while True:
        player: str = random.choice(PLAYERS)
        action: str = random.choice(ACTIONS)

        player_with_action: tuple[str, str] = (player, action)
        yield player_with_action


def consume_event(
        list_of_events: list[tuple[str, str]]
) -> Generator[tuple[str, str], None, None]:
    """
    A function, that also becomes a generator using the "yield"
    keyword.

    This generator use random.randrange() to get a random index.
    Afterwards, we .pop() at the index we previously got and yield
    the result.
    """

    while list_of_events:
        event_index: int = random.randrange(len(list_of_events))

        removed: tuple[str, str] = list_of_events.pop(event_index)

        yield removed


def main() -> None:
    """
    The main responsible of doing all the tests.

    We use it to generate with the gen_event() generator, thousand
    tuple() of player with their action.
    Afterward, we create a list holding ten random tuples.
    And finally the consume_event() generator will remove a random
    tuple() from the list, and we print the removed event as well as
    the current list[tuple[str, str]] without the removed element.
    """

    print(HEADER)

    event_stream: Generator[tuple[str, str], None, None] = gen_event()

    for n in range(1000):
        event: tuple[str, str] = next(event_stream)

        print(f"Event {n}: Player {event[0]} did action {event[1]}")

    list_of_events: list[tuple[str, str]] = []

    for _ in range(10):
        list_of_events.append(next(event_stream))

    print(f"Built list of {len(list_of_events)} events: {list_of_events}")

    consume_stream: Generator[tuple[str, str], None, None] = (
            consume_event(list_of_events)
    )

    for ev in consume_stream:
        print(f"Got event from list: {ev}")
        print(f"Remains in list: {list_of_events}")


# ---- Run the code
if __name__ == "__main__":
    # This line runs the block of code if we call the program DIRECTLY,
    # but will not do so, if we importing it.

    main()
