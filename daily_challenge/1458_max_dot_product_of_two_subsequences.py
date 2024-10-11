"""
Problem Statement:
Given two arrays nums1 and nums2.

Return the maximum dot product between non-empty subsequences of nums1 and nums2 with the same length.

A subsequence of a array is a new array which is formed from the original array by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, [2,3,5] is a subsequence of [1,2,3,4,5] while [1,5,3] is not).

Constraints:
1 <= nums1.length, nums2.length <= 500
-1000 <= nums1[i], nums2[i] <= 1000

Difficulty: Hard

"""

#Time Complexity: O(n^2)
class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        length_1 = len(nums1)+1
        length_2 = len(nums2)+1
        hash_table = [[float('-inf')]*length_2 for x in range(length_1)]
        for i in range(1,length_1):
            for j in range(1,length_2):
                hash_table[i][j] = max(hash_table[i-1][j-1]+nums1[i-1]*nums2[j-1],hash_table[i-1][j],hash_table[i][j-1],nums1[i-1]*nums2[j-1])
        return hash_table[length_1-1][length_2-1]


"Reference/Insight used to solve the problem: https://leetcode.com/submissions/detail/1069897640/"
