"""
Problem Statement:
You are given a 0-indexed 2D integer array flowers, where flowers[i] = [starti, endi] means the ith flower will be in full bloom from starti to endi (inclusive). You are also given a 0-indexed integer array people of size n, where people[i] is the time that the ith person will arrive to see the flowers.

Return an integer array answer of size n, where answer[i] is the number of flowers that are in full bloom when the ith person arrives.

Constraints:
1 <= flowers.length <= 5 * 104
flowers[i].length == 2
1 <= starti <= endi <= 109
1 <= people.length <= 5 * 104
1 <= people[i] <= 109

Difficulty: Hard

"""

#Time Complexity: O((m+n)log(m))
class Solution:
    def fullBloomFlowers(self, flowers: List[List[int]], people: List[int]) -> List[int]:
        start = []
        end = []
        full_bloom=[]
        for s,e in flowers:
            start.append(s)
            end.append(e)
        start.sort()
        end.sort()
        for p in people:
            #returns index where p can be inserted which maintains the array sorted
            i = bisect_right(start,p)
            j = bisect_left(end,p)
            full_bloom.append(i-j)           
        return full_bloom


"Reference/Insight used to solve the problem: https://leetcode.com/problems/number-of-flowers-in-full-bloom/editorial/"