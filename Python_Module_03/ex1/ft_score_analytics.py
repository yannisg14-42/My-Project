#!/usr/bin/env python3

import sys


# >>>Global Constants<<<

BANNER: str = "<|> Player Score Analytics <|>"
EMPTY_SCORE: str = "No scores provided. Usage: " \
                    "python3 ft_score_analytics.py <score1> <score2> ..."
SCORE_LIST: str = "Scores at our disposal (ㆆ_ㆆ)"
PLAYER_LIST: str = "Players ready ᕙ( •̀ ᗜ •́ )ᕗ"
SCORES_SUM: str = "All scores added together ✎﹏﹏﹏﹏"
AVERAGE_SCORES: str = "The average score ✎﹏﹏﹏﹏"
HIGH_SCORE: str = "You won ( ◡̀_◡́)ᕤ"
LOW_SCORE: str = "You Lost (╥ ᴗ ╥)"
RANGE_SCORE: str = "Range of our scores ✎﹏﹏﹏﹏"
WRONG_PARAMETER: str = "This score is not a valid number (•ˋ _ ˊ•)"


def ft_score_analytics() -> None:

    """
    This program takes
    """

    score_list: list[int] = []

    print(BANNER)

    score_index: int = 1
    len_without_program_name: int = len(sys.argv) - 1

    while score_index <= len_without_program_name:
        try:
            score_list.append(int(sys.argv[score_index]))

        except ValueError:
            print(f"{WRONG_PARAMETER} '{sys.argv[score_index]}'")

        score_index += 1

    if not score_list:
        print(EMPTY_SCORE)

    else:
        print(f"{SCORE_LIST} {score_list}")

        print(f"{PLAYER_LIST} {len(score_list)}")

        print(f"{SCORES_SUM} {sum(score_list)}")

        print(f"{AVERAGE_SCORES} {sum(score_list) / len(score_list):.1f}")

        print(f"{HIGH_SCORE} {max(score_list)}")

        print(f"{LOW_SCORE} {min(score_list)}")

        print(f"{RANGE_SCORE} {max(score_list) - min(score_list)}")


# >>>>Runs the Code<<<<

if __name__ == "__main__":

    # This line runs the block of if we call the program DIRECTLY,
    # but will not, if it is imported.

    ft_score_analytics()
