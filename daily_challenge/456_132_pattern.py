"""
Problem:
Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.

Constraints:

n == nums.length
1 <= n <= 2 * 105
-109 <= nums[i] <= 109

Difficulty: Medium
"""

"Solution: Time Complexity: O(n)"
class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        length = len(nums)
        if length<3:
            return False
        
        min_array = [nums[0]]
        stack = []
        
        for i in range(1,length):
            min_array.append(min(min_array[i-1],nums[i])) 
        
        for i in range(length-1,-1,-1):
            if nums[i]>min_array[i]:
                #if element is < min this can't be 2
                while stack and stack[-1]<=min_array[i]:
                    stack.pop()
                #stack has 2 (min[i] is 1 and nums[i] is 3)
                if stack and stack[-1]<nums[i]:
                    return True
                #This can be 2
                stack.append(nums[i])

        return False