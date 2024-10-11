"""
Problem Statement:
Given an array of integers nums, return the number of good pairs.

A pair (i, j) is called good if nums[i] == nums[j] and i < j.

Constraints:
1 <= nums.length <= 100
1 <= nums[i] <= 100

Difficulty: Easy

"""

#Time Complexity: O(n)
class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        good_pair = dict()
        length = len(nums)
        if length<2:
            return 0
        #Get count of each integer occurence
        for i in range(length):
            if nums[i] not in good_pair.keys():
                good_pair[nums[i]] = 1
            else:
                good_pair[nums[i]]+=1

        count = 0
        #n*(n-1)/2 to get good_pair count
        for value in good_pair.values():
            count+=(value*(value-1))//2
        return count

"Reference/Insight used to solve the problem: None"