"""
Problem Statement:
You have a pointer at index 0 in an array of size arrLen. At each step, you can move 1 position to the left, 1 position to the right in the array, or stay in the same place (The pointer should not be placed outside the array at any time).

Given two integers steps and arrLen, return the number of ways such that your pointer is still at index 0 after exactly steps steps. Since the answer may be too large, return it modulo 109 + 7.

Constraints:
1 <= steps <= 500
1 <= arrLen <= 106

Difficulty: Hard

"""

#Time Complexity: O(n*min(n,m))
class Solution:
    def numWays(self, steps: int, arrLen: int) -> int:
        MOD = 10 ** 9 + 7
        arrLen = min(arrLen, steps)
        dp = [[0] * (steps + 1) for _ in range(arrLen)]
        dp[0][0] = 1
        
        for remain in range(1, steps + 1):
            for curr in range(arrLen - 1, -1, -1):
                ans = dp[curr][remain - 1]
                
                if curr > 0:
                    ans = (ans + dp[curr - 1][remain - 1]) % MOD
                
                if curr < arrLen - 1:
                    ans = (ans + dp[curr + 1][remain - 1]) % MOD
                
                dp[curr][remain] = ans
        
        return dp[0][steps]

"Reference/Insight used to solve the problem: https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/editorial/"
#Copied: have to practice dp approach