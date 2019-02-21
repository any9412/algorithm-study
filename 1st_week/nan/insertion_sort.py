#!/usr/bin/env python3

"""
This is how insertion sort works.
"""

import random


def main():
    inputs = [i for i in range(1, 10)]
    random.shuffle(inputs)
    print("inputs: ", inputs)

    for i in range(1, len(inputs)):
        tmp = inputs[i]
        for j in reversed([i for i in range(0, i)]):
            if tmp < inputs[j]:
                inputs[inputs.index(tmp)] = inputs[j]
                inputs[j] = tmp
    print("result: ", inputs)


if __name__ == '__main__':
    main()
