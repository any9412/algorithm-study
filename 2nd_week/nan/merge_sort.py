#!/usr/bin/env python3

"""
This is how merge sort works.
"""

import random


def conquer(A: 'List[int]', B: 'List[int]') -> 'List[int]':
    # print("conquer A: {0}, B: {1}".format(A, B))
    tmp = []
    a, b = int(0), int(0)
    while a < len(A) and b < len(B):
        if A[a] > B[b]:
            tmp.append(B[b])
            b += 1
        else:
            tmp.append(A[a])
            a += 1
    if a < len(A):
        tmp.extend(A[a:])
    elif b < len(B):
        tmp.extend(B[b:])
    return tmp


def combine(A: 'List[int]', B:'List[int]') -> 'List[int]':
    # print("combine A:{0}, B; {1}".format(A, B))
    A.extend(B)
    A.sort()
    return A


def divide(A: 'List[int]', res: 'List[List[int]]'):
    # print("divide A:{0}, res: {1}".format(A, res))
    if len(A) > 2 :
        divide(A[: len(A)//2], res)
        divide(A[(len(A)//2):], res)
    else:
        combine(res, sorted(A))


def main():
    inputs = [i for i in range(0, 10)]
    random.shuffle(inputs)
    print("inputs: ", inputs)
    res, left, right = [], [], []
    divide(inputs[:len(inputs)//2], left)
    divide(inputs[len(inputs)//2:], right)
    res = conquer(left, right)
    print("result: ", res)


if __name__ == '__main__':
    main()
