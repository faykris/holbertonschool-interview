#!/usr/bin/python3
"""Lockboxes module"""


def canUnlockAll(boxes):
    """canUnlockAll function"""
    i = 0
    for box in boxes:
        open_box = False
        if i != 0:
            for j in range(len(boxes)):
                if i in boxes[j] and i != j:
                    open_box = True
                    break
            if open_box is False:
                return False
        i += 1
    return True
