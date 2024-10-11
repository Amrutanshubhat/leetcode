"""
Problem Statement:
Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.

Return any array that satisfies this condition.

Constraints:

1 <= nums.length <= 5000
0 <= nums[i] <= 5000

Problem complexity: Easy
"""



"Solution: time complexity- O(n)"
class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        index = 0
        length = len(nums)
        for i in range(length):
            "Swap even numbers to array initials"
            if nums[i]%2==0:
                nums[index],nums[i] = nums[i],nums[index]
                index+=1

        return nums
    