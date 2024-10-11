"""
Problem Statement:
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

Constraints:
2 <= cost.length <= 1000
0 <= cost[i] <= 999

"""

#Time Complexity: O(n)
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        total_cost = 0
        length = len(cost)+1
        arr = [0,0,0]   
        for i in range(3,length+1):
            arr.append(min(cost[i-3]+arr[i-2],cost[i-2]+arr[i-1]))
            
        return arr[-1]

"Reference/Insight used to solve the problem:https://leetcode.com/submissions/detail/1074093887/ "
