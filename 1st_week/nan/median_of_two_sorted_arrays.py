#!/usr/bin/env python3

"""
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
"""


class Solution:
    def findMedianSortedArrays(self, nums1: 'List[int]', nums2: 'List[int]') -> 'float':
        nums1.extend(nums2)
        nums1.sort()
        if len(nums1) % 2 == 0:
            return (nums1[len(nums1)//2 -1] + nums1[len(nums1)//2])/2
        else:
            return nums1[len(nums1)//2]


def main():
    # testcase1
    a, b = [1,2,3], [2,3]
    solution = Solution()
    print(solution.findMedianSortedArrays(a, b))

    #testcase2
    a, b = [1,2,5,7], [2,5,6,7,9,11]
    print(solution.findMedianSortedArrays(a, b))


if __name__ == '__main__':
    main()