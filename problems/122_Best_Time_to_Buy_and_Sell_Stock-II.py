'''
Problem Statement-

-----------------------------------------------------------------

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

----------------------------------------------------------------- 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.

----------------------------------------------------------------- 

Constraints:

1 <= prices.length <= 3 * 104
0 <= prices[i] <= 104

'''

#Solution 1: Time Complexity - O(n^n) 
# Brute Force method. 198/200 Testcases passed.
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        days = len(prices)
        if days<2:
            return 0
        max_profit = 0

        for i in range(days):
            local_max = 0
            for j in range(i+1,days):
                profit = 0
                if prices[j]>prices[i]:
                    profit = self.maxProfit(prices[j:])+(prices[j]-prices[i])
                if profit>local_max:
                    local_max = profit

            if local_max>max_profit:
                max_profit = local_max
        
        return max_profit

#Solution 2: Peak Valley approach - O(n) 

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        days = len(prices)
        if days<2:
            return 0
        max_profit = 0
        sell_high=0
        buy_low=0
        i=0
        while i<days-1:
            while (i<days-1) and (prices[i]>=prices[i+1]):
                i+=1
            buy_low = prices[i]
            while (i<days-1) and (prices[i]<=prices[i+1]):
                i+=1
            sell_high = prices[i]
            max_profit+= sell_high - buy_low
        return max_profit

        