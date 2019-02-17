#!/usr/bin/env python3

"""
This is how selection sort works.
"""

import random


def main():
    inputs = [i for i in range(1, 10)]
    random.shuffle(inputs)
    print("inputs: ", inputs)
    for i in range(len(inputs)):
        min_index = i
        for j in range(i+1, len(inputs)):
            if inputs[min_index] > inputs[j]:
                min_index = j
        tmp = inputs[i]
        inputs[i] = inputs[min_index]
        inputs[min_index] = tmp
    print("result: ", inputs)


if __name__ == '__main__':
    main()
