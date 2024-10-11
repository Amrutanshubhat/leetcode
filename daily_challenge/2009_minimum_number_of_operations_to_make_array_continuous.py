"""
Problem Statement:
You are given an integer array nums. In one operation, you can replace any element in nums with any integer.

nums is considered continuous if both of the following conditions are fulfilled:

All elements in nums are unique.
The difference between the maximum element and the minimum element in nums equals nums.length - 1.
For example, nums = [4, 2, 5, 3] is continuous, but nums = [1, 2, 3, 5, 6] is not continuous.

Return the minimum number of operations to make nums continuous.


Constraints:
1 <= nums.length <= 105
1 <= nums[i] <= 109

Difficulty: Hard

"""

#Time Complexity: O(nlogn)
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        length = len(nums)
        cond = length-1
        if not cond:
            return 0
        unique_nums = sorted(set(nums))
        len_ = len(unique_nums)
        min_op = float('inf')
        j=0
        for i in range(len_):
            target = unique_nums[i]+cond
            while(j<len_ and unique_nums[j]<=target):
                j+=1
            min_op = min(min_op,length-(j-i))
        return min_op

"Reference/Insight used to solve the problem: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/editorial/"