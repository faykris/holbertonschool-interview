#!/usr/bin/python3
"""Lockboxes module"""

def join(t, r):
    """join function"""
    res = []
    for e in r:
        res += t[e]
    return res


def canUnlockAll(boxes):
    """canUnlockAll function"""
    i = 0
    total = list(set(boxes[0]) | {0})
    added = True
    while added:
        added = False
        for j in join(boxes, total[i:]):
            if j not in total:
                total.append(j)
                i += 1
                added = True

    return len(total) == len(boxes)
