#!/usr/bin/env python3
"""
S and T are strings composed of lowercase letters. In S, no letter occurs more than once.

S was sorted in some custom order previously. We want to permute the characters of T so that they match the order that S was sorted. More specifically, if x occurs before y in S, then x should occur before y in the returned string.

Return any permutation of T (as a string) that satisfies this property.

Example :
Input:
S = "cba"
T = "abcd"
Output: "cbad"
Explanation:
"a", "b", "c" appear in S, so the order of "a", "b", "c" should be "c", "b", and "a".
Since "d" does not appear in S, it can be at any position in T. "dcba", "cdba", "cbda" are also valid outputs.


Note:

S has length at most 26, and no character is repeated in S.
T has length at most 200.
S and T consist of lowercase letters only.
"""


class Solution:
    def custom_sort_string(self, S: 'str', T: 'str') -> 'str':
        char_in_s, char_not_in_s = [], []
        for i in T:
            if i in S:
                char_in_s.append(i)
            else:
                char_not_in_s.append(i)
        order = [[i,0] for i in char_in_s]
        for i in order:
            i[1] = S.index(i[0])
        order = sorted(order, key=lambda o: o[1])
        res = ''.join(i[0] for i in order) + ''.join(char_not_in_s)
        return res


def main():
    solution = Solution()
    print(solution.customSortString("cba", "abcd"))


if __name__ == '__main__':
    main()
