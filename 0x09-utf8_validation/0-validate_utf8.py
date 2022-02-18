#!/usr/bin/python3
"""0. UTF-8 Validation"""


def validUTF8(data):
    """validUTF8 - verify if data is a valid UTF-8"""
    i = 0
    for num in data:
        bits = format(num, '#010b')[-8:]
        if i == 0:
            if bits[0] == '1':
                i = len(bits.split('0')[0])
            if i == 0:
                continue
            if i > 4 or i == 1:
                return False
        else:
            if not (bits[0] == '1' and bits[1] == '0'):
                return False
        i -= 1
    if i != 0:
        return False
    return True
