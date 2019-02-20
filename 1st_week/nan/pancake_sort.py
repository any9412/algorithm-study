#!/usr/bin/env python3

"""
Given an array A, we can perform a pancake flip: We choose some positive integer k <= A.length, then reverse the order of the first k elements of A.  We want to perform zero or more pancake flips (doing them one after another in succession) to sort the array A.

Return the k-values corresponding to a sequence of pancake flips that sort A.  Any valid answer that sorts the array within 10 * A.length flips will be judged as correct.

Example 1:

Input: [3,2,4,1]
Output: [4,2,4,3]
Explanation:
We perform 4 pancake flips, with k values 4, 2, 4, and 3.
Starting state: A = [3, 2, 4, 1]
After 1st flip (k=4): A = [1, 4, 2, 3]
After 2nd flip (k=2): A = [4, 1, 2, 3]
After 3rd flip (k=4): A = [3, 2, 1, 4]
After 4th flip (k=3): A = [1, 2, 3, 4], which is sorted.

Example 2:

Input: [1,2,3]
Output: []
Explanation: The input is already sorted, so there is no need to flip anything.
Note that other answers, such as [3, 3], would also be accepted.
"""


class Solution:
    def findLargestElement(self, A: 'List[int]') -> 'List[int]':
        for i in A:
            if max(A) == i:
                return [i, A.index(i)]
        
    def pancakeSort(self, A: 'List[int]') -> 'List[int]':
        index = len(A) - 1
        res = []
        while True:
            if index == 0:
                break
            tmp = A[:index+1]
            tmp_res = self.findLargestElement(tmp)
            if not tmp[index] == tmp_res[0]:
                t = tmp[:tmp_res[1]+1]
                res.append(tmp_res[1]+1)
                t.reverse()
                t.extend(tmp[tmp_res[1]+1:])
                t.extend(tmp[index+1:])
                t.reverse()
                t.extend(A[len(t):])
                A = t
            else:
                if index > 1:
                    res.append(index+1)
                index -= 1
        print("sorted A: {0}".format(A))
        return res


def main():
    testcase1 = [3,2,4,1]
    testcase2 = [85,76,78,17,96,73,30,31,84,42,64,88,22,4,10,43,3,41,14,87,34,77,100,11,66,94,75,54,27,2,97,28,32,92,50,86,25,7,83,89,48,9,16,24,59,99,33,38,82,55,71,26,21,45,93,91,53,81,61,68,98,51,23,62,12,13,63,60,1,56,19,8,15,6,35,74,57,5,52,37,36,29,40,70,44,67,79,90,95,46,47,20,18,80,72,65,49,69,58,39]

    print("==============================")
    print("testcase1")
    print("res: {0}".format(Solution().pancakeSort(testcase1)))
    print("==============================")
    print("testcase2")
    print("res: {0}".format(Solution().pancakeSort(testcase2)))
    print("==============================")


if __name__ == '__main__':
    main()
