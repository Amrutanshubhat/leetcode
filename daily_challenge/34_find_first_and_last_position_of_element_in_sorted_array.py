"""
Problem Statement:
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Constraints:
0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109

Difficulty: Medium

"""

#Time Complexity: O(logn)
class Solution:
    #binary search function to get the target index
    def get_index(self,nums,target,start,end):
        if start>end:
            return -1
        mid = (end-start)//2
        pointer = start+mid
        if nums[pointer]==target:
            return pointer
        elif nums[pointer]>target:
            return self.get_index(nums,target,start,pointer-1)
        else:
            return self.get_index(nums,target,pointer+1,end)
        
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        length = len(nums)
        #get the index of the target in nums
        index = self.get_index(nums,target,start=0,end=length-1)
        start=end=index
        #move out in both the direction to get the range
        while start>0 and nums[start-1]==target:
            start-=1
        while end<length-1 and nums[end+1]==target:
            end+=1
        return [start,end]        

"Reference/Insight used to solve the problem: None"
