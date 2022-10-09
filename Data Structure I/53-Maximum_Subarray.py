'''
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.

 
Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Example 2:

Input: nums = [1]
Output: 1

Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
'''
#Solution 1 : Time Complexity: O(n^2)
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        arr_len = len(nums)
        max_sum=nums[0]
        for i in range(arr_len):
            loc_sum=nums[i]
            for j in range(i-1,-1,-1):
                if max_sum<loc_sum:
                    max_sum=loc_sum
                loc_sum+=nums[j]
            if max_sum<loc_sum:
                    max_sum=loc_sum
        return max_sum

#Solution 2 : Time Complexity: O(nlogn)
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        l = 0
        u = len(nums)-1
        if(l>u):
            return -99999999999999999
        if(l==u):
            return nums[l]
        m = (u+1)//2
        lmax = sum_ = nums[m-1]
        for i in range(m-2,l-1,-1):
            sum_+=nums[i]
            lmax=max(lmax,sum_)
        rmax = sum_ = nums[m]
        for i in range(m+1,u+1):
            sum_+=nums[i]
            rmax=max(rmax,sum_)
        return max(lmax+rmax,self.maxSubArray(nums[:m]),self.maxSubArray(nums[m:]))

#Solution 3: Time Complexity: O(1)
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxhere = 0
        max_=nums[0]
        n = len(nums)
        for i in range(n):
            maxhere = max(maxhere+nums[i],nums[i])
            max_ = max(max_, maxhere)
        return max_