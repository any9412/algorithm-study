#!/usr/bin/env python3

"""
This is how bubble sort works.
"""

import random


def main():
    inputs = [i for i in range(1, 10)]
    random.shuffle(inputs)
    print("inputs: ", inputs)

    for i in range(len(inputs)):
        for j in range(0, len(inputs)-i-1):
            if inputs[j] > inputs[j+1]:
                tmp = inputs[j]
                inputs[j] = inputs[j+1]
                inputs[j+1] = tmp
    print("result: ", inputs)


if __name__ == '__main__':
    main()
