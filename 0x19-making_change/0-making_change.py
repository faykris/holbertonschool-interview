#!/usr/bin/python3
"""0. Change comes from within"""


def makeChange(coins, total):
    """makeChange - function"""

    change = 0
    sw = True
    if(total <= 0):
        return 0
    else:
        while sw is True:
            save = change
            for coin in sorted(coins, reverse=True):
                if total >= coin:
                    if total % coin == 0:
                        change = int(change + total / coin)
                        sw = False
                        break
                    else:
                        change = int(change + total / coin)
                        total = total % coin
                        break
            if change is save:
                return -1
    return int(change)
