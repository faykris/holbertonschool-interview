#!/usr/bin/python3
"""0. Change comes from within"""


def makeChange(coins, total):
    """makeChange - function"""

    if total <= 0:
        return 0

    coins.sort(reverse=True)
    stack = total
    mv = 0
    cnt = 0
    while (mv < len(coins)):
        if stack == 0:
            return cnt
        if coins[mv] > stack:
            mv += 1
        else:
            stack -= coins[mv]
            cnt += 1
    return -1
