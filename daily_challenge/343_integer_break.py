"""
Problem Statement:
Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.

Return the maximum product you can get.

Constraints:
2 <= n <= 58


Difficulty:Medium

"""

#Time Complexity:O(1)
class Solution:
    def integerBreak(self, n: int) -> int:
        #check for base case
        if n<=2:
            return 1
        if n==3:
            return 2
        #3^n FTW
        "3logn grows faster than 2logn. every integer post 3 can be rewritten in terms of 3^n*reminder which yields maximum product"
        mul = n//3
        rem = n%3
        if rem==0:
            return 3**mul
        elif rem==1:
            return (3**(mul-1))*4
        else:
            return (3**(mul))*rem


"Reference/Insight used to solve the problem: None"
