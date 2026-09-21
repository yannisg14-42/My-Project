#!/usr/bin/env python3

import sys


# >>>Global Constants<<<

BANNER: str = "<|> Player Score Analytics <|>"
EMPTY_SCORE: str = "No scores provided. Usage: " \
                    "python3 ft_score_analytics.py <score1> <score2> ..."
SCORE_LIST: str = "Scores at our disposal (ㆆ_ㆆ)"
PLAYER_COUNT: str = "Players ready ᕙ( •̀ ᗜ •́ )ᕗ"
SCORES_SUM: str = "All scores added together ✎﹏﹏﹏﹏"
AVERAGE_SCORES: str = "The average score ✎﹏﹏﹏﹏"
HIGH_SCORE: str = "You won ( ◡̀_◡́)ᕤ"
LOW_SCORE: str = "You Lost (╥ ᴗ ╥)"
RANGE_SCORE: str = "Range of our scores ✎﹏﹏﹏﹏"
WRONG_PARAMETER: str = "This score is not a valid number (•ˋ _ ˊ•)"


def ft_score_analytics() -> None:

    """
    This program takes an unlimited number of parameters at run time
    and display a game board with the following spec.
    If there is no parameters, it display a simple instruction message.
    if we have only invalid parameters, it diplay them, then show again
    the instruction message since we have no valid parameters.
    If we have a mix of valid and invalid parameters, or simply
    all of them valid, the invalid ones are displayed and the program
    create a list with the valid parameters. With this list we can create
    the gameboard with useful informations, like max and min scores,
    the average score, number of players etc.
    """

    score_list: list[float] = []
    inf: float = float("inf")
    minus_inf: float = float("-inf")

    print(BANNER)

    score_index: int = 1
    len_without_program_name: int = len(sys.argv) - 1

    while score_index <= len_without_program_name:
        try:
            player_score: float = float(sys.argv[score_index])
            if player_score < inf and player_score > minus_inf:
                score_list.append(player_score)

        except ValueError:
            print(f"{WRONG_PARAMETER} '{sys.argv[score_index]}'")

        score_index += 1

    if not score_list:
        print(EMPTY_SCORE)

    else:
        print(f"{SCORE_LIST} {score_list}")

        print(f"{PLAYER_COUNT} {len(score_list)}")

        print(f"{SCORES_SUM} {sum(score_list)}")

        print(f"{AVERAGE_SCORES} {sum(score_list) / len(score_list):.2f}")

        print(f"{HIGH_SCORE} {max(score_list)}")

        print(f"{LOW_SCORE} {min(score_list)}")

        print(f"{RANGE_SCORE} {max(score_list) - min(score_list)}")


# >>>>Runs the Code<<<<

if __name__ == "__main__":

    # This line runs the block of if we call the program DIRECTLY,
    # but will not, if it is imported.

    ft_score_analytics()
