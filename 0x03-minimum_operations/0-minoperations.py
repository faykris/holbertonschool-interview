#!/usr/bin/python3
"""
Minimum operators - module
"""


def minOperations(n):
    """Minimum operators - function"""
    ope = 0
    buffer = 'H'
    copy = ''
    copied = False

    if n > 0:
        for i in range(n):
            if len(buffer) != n:
                ope += 1
                if copied is False:
                    # Copy all
                    copy = buffer
                    copied = True
                else:
                    # Paste
                    buffer += copy
                    if n % len(buffer) == 0:
                        copied = False
    return ope
