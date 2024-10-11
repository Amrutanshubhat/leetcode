"""
Problem Statement:
(This problem is an interactive problem.)

You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target. If such an index does not exist, return -1.

You cannot access the mountain array directly. You may only access the array using a MountainArray interface:

MountainArray.get(k) returns the element of the array at index k (0-indexed).
MountainArray.length() returns the length of the array.
Submissions making more than 100 calls to MountainArray.get will be judged Wrong Answer. Also, any solutions that attempt to circumvent the judge will result in disqualification.


Constraints:
3 <= mountain_arr.length() <= 104
0 <= target <= 109
0 <= mountain_arr.get(index) <= 109

Difficulty: Hard

"""

#Time Complexity: O(logn)

# """
# This is MountainArray's API interface.
# You should not implement it, or speculate about its implementation
# """
#class MountainArray:
#    def get(self, index: int) -> int:
#    def length(self) -> int:

class Solution:
    def index_search(self,start,end,mountain):
        diff = end-start
        if diff<2:
            return -1
        mid = start+(diff//2)
        mid_val = mountain.get(mid)
        left_val = mountain.get(mid-1)
        right_val = mountain.get(mid+1)
        if left_val<mid_val<right_val:
            return self.index_search(mid,end,mountain)
        elif left_val>mid_val>right_val:
            return self.index_search(start,mid,mountain)
        else:
            #print(f"Found: left:{left_val}\nright: {right_val}")
            return mid

    def target_search_left(self,start,end,target,mountain):
        diff = end-start
        if diff<0:
            return -1
        if diff==0:
            if mountain.get(start)==target:
                return start
            return -1
        mid = start+(diff//2)
        mid_val = mountain.get(mid)
        #print(f"start: {start} mid: {mid} end: {end}")
        if mid_val == target:
            return mid
        elif mid_val<target:
            return self.target_search_left(mid+1,end,target,mountain)
        else:
            return self.target_search_left(start,mid-1,target,mountain)

    def target_search_right(self,start,end,target,mountain):
        diff = end-start
        if diff<0:
            return -1
        if diff==0:
            if mountain.get(start)==target:
                return start
            return -1

        mid = start+(diff//2)
        mid_val = mountain.get(mid)
        if mid_val == target:
            return mid
        elif mid_val<target:
            return self.target_search_right(start,mid-1,target,mountain)
        else:
            return self.target_search_right(mid+1,end,target,mountain)
        

    def findInMountainArray(self, target: int, mountain_arr: 'MountainArray') -> int:
        length = mountain_arr.length()
        #get mountain peak
        pivot = self.index_search(0,length-1,mountain_arr)
        #search downhill to get lower index if the target if present on both the side of the mountain
        find_left = self.target_search_left(0,pivot,target,mountain_arr)
        #if the target is not found on left side search in the right side of the downhill
        if find_left == -1:
            return self.target_search_right(pivot,length-1,target,mountain_arr)
        #returns -1 if not found
        return find_left


"Reference/Insight used to solve the problem: None"