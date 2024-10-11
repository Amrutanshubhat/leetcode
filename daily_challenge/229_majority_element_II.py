"""
Problem Statement:
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Constraints:
1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109

Difficulty: Medium

"""

#Time Complexity: O(n)
class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        counter = dict()
        length = len(nums)
        limit = length//3
        if not limit:
            return list(set(nums))
        for i in nums:
            try:
                counter[i]+=1
            except KeyError:
                counter[i]=1
        
        lst = []
        for key,value in counter.items():
            if value>limit:
                lst.append(key)
        return lst

"Reference/Insight used to solve the problem: None"