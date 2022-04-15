#!/usr/bin/python3
"""
0. Rain
"""


def rain(walls):
    """rain function"""
    if len(walls) == 0 or type(walls) != list:
        return 0
    water = 0
    i = 0
    while i < len(walls) - 1:
        if (i == 0 and walls[i] != 0) or\
                (i != 0 and walls[i + 1] == 0 and i + 1 != len(walls) - 1):
            start = i
            i += 1
            mul = 1
            while i < len(walls) - 1 and walls[i + 1] == 0:
                mul += 1
                i += 1
            if i + 1 < len(walls) - 1:
                if walls[i + 1] >= walls[start]:
                    water += walls[start] * mul
                else:
                    water += walls[i + 1] * mul
        i += 1
    return water
