#!/usr/bin/python3
"""
0. Pascal's Triangle - module
"""


def pascal_triangle(n):
    """
    Returns list of lists of integers representing the Pascal’s triangle of n
    """

    triangle = []
    if n <= 0:
        return triangle
    previous = [1]
    for row_index in range(n):
        row_list = []
        if row_index == 0:
            row_list = [1]
        else:
            for i in range(row_index + 1):
                if i == 0:
                    row_list.append(0 + previous[i])
                elif i == row_index:
                    row_list.append(previous[i - 1] + 0)
                else:
                    row_list.append(previous[i - 1] + previous[i])
        previous = row_list
        triangle.append(row_list)
    return triangle
