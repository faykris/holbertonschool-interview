#!/usr/bin/python3
"""0. Rotate 2D Matrix"""

def rotate_2d_matrix(matrix):
    """Rotate it 90 degrees clockwise"""
    rows = len(matrix)

    for row in range(int(rows / 2)):
        y = (rows - row - 1)
        for col in range(row, y):
            x = (rows - 1 - col)
            tmp = matrix[row][col]
            matrix[row][col] = matrix[x][row]
            matrix[x][row] = matrix[y][x]
            matrix[y][x] = matrix[col][y]
            matrix[col][y] = tmp
