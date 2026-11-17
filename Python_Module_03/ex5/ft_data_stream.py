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
    """

    while True:
        player: str = random.choice(PLAYERS)
        action: str = random.choice(ACTIONS)

        player_with_action: tuple[str, str] = (player, action)
        yield player_with_action

def consume_event() -> Generator[list[tuple], None, None] :
    """
    """

    event: tuple(str, str)
def main() -> None:
    """
    """

    print(HEADER)

    event_stream: Generator[tuple[str, str], None, None] = gen_event()

    for n in range(1000):
        event: tuple[str, str] = next(event_stream)

        print(f"Event {n}: Player {event[0]} did action {event[1]}")

    list_of_events: list[tuple[str, str]] = []

    for i in range(10):
        list_of_events.append(next(event_stream))

    print(f"Built list of {len(list_of_events)} events: {list_of_events}")


# ---- Run the code
if __name__ == "__main__":
    # This line runs the block of code if we call the program DIRECTLY,
    # but will not do so, if we importing it.

    main()

