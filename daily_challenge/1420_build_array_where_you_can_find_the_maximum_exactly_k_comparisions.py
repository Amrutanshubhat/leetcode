"""
Problem Statement:
You are given three integers n, m and k. Consider the following algorithm to find the maximum element of an array of positive integers:
You should build the array arr which has the following properties:

arr has exactly n integers.
1 <= arr[i] <= m where (0 <= i < n).
After applying the mentioned algorithm to arr, the value search_cost is equal to k.
Return the number of ways to build the array arr under the mentioned conditions. As the answer may grow large, the answer must be computed modulo 109 + 7.


Constraints:
1 <= n <= 50
1 <= m <= 100
0 <= k <= n

Difficulty: Hard

"""

#Time Complexity:O(n^3) 
class Solution:
    def numOfArrays(self, n: int, m: int, k: int) -> int:
        self.mod = 10**9+7
        # Initialize a 3D array 'dp' to store intermediate results
        dp = [[[0 for _ in range(k + 1)] for _ in range(m + 1)] for _ in range(n + 1)]

        # Initialize a 3D array 'sum_arr' to store cumulative sums
        sum_arr = [[[0 for _ in range(k + 1)] for _ in range(m + 1)] for _ in range(2)]

        # Initialize the base case for dp and sum_arr for sz=1
        for i in range(1, m + 1):
            dp[1][i][1] = 1
            sum_arr[1][i][1] = i

        # Iterate over 'sz' (size), 'maxN' (maximum number), and 'cost' (cost)
        for sz in range(1, n + 1):
            for maxN in range(1, m + 1):
                for cost in range(1, k + 1):
                    # Calculate 'ans' based on the recurrence relation
                    ans = (maxN * dp[sz - 1][maxN][cost]) % self.mod
                    ans = (ans + sum_arr[(sz - 1) & 1][maxN - 1][cost - 1]) % self.mod

                    # Update 'dp' with the computed 'ans' and take modulo
                    dp[sz][maxN][cost] = (dp[sz][maxN][cost] + ans) % self.mod

                    # Update 'sum_arr' with the cumulative sum of 'dp'
                    sum_arr[sz & 1][maxN][cost] = (sum_arr[sz & 1][maxN - 1][cost] + dp[sz][maxN][cost]) % self.mod

        # Return the result from 'sum_arr' based on the provided inputs
        return sum_arr[n & 1][m][k]


"Reference/Insight used to solve the problem: https://leetcode.com/submissions/detail/1069199771/"
#Haven't gone through the problem. Just pasted the solution mention above.
