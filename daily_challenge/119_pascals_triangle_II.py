"""
Problem Statement:
Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Constraints: 0 <= rowIndex <= 33

Difficulty: Easy

"""

#Time Complexity:O(n^2)
class Solution(object):

    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        if rowIndex<1:
            return [1]
        pascal = [1,1]
        for i in range(rowIndex):
            output = [1,1]
            for j in range(i):
                output.insert(j+1,pascal[j]+pascal[j+1])
            #print(output)
            pascal = output
        return pascal

"Reference/Insight used to solve the problem: None"
