"""
Problem Statement:
An array is monotonic if it is either monotone increasing or monotone decreasing.

An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].

Given an integer array nums, return true if the given array is monotonic, or false otherwise.

Constraints:

1 <= nums.length <= 105
-105 <= nums[i] <= 105

Difficulty Level: Easy
"""

"Solution: Time Complexity - O(n)"
class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        length = len(nums)
        if length==1:
            return True
        mono_inc = True
        mono_dec = True
        for i in range(length-1):
            if nums[i]<nums[i+1]:
                mono_dec = False
            elif nums[i]>nums[i+1]:
                mono_inc = False
            else:
                pass
            #Exit if the array is neither increasing monotone or decreasing monotone
            if not (mono_dec or mono_inc):
                return False

        return True