#!/usr/bin/python3
"""0. Change comes from within"""


def makeChange(coins, total):
    """makeChange - function"""

    sum = 0
    if (total <= 0):
        return 0
    coins.sort(reverse=True)
    for i in coins:
        if (total < i):
            pass
        q, r = divmod(total, i)
        total = r
        sum += q
    if (total != 0):
        return -1
    return sum
