"""
Problem Statement:
There are n pieces arranged in a line, and each piece is colored either by 'A' or by 'B'. You are given a string colors of length n where colors[i] is the color of the ith piece.

Alice and Bob are playing a game where they take alternating turns removing pieces from the line. In this game, Alice moves first.

Alice is only allowed to remove a piece colored 'A' if both its neighbors are also colored 'A'. She is not allowed to remove pieces that are colored 'B'.
Bob is only allowed to remove a piece colored 'B' if both its neighbors are also colored 'B'. He is not allowed to remove pieces that are colored 'A'.
Alice and Bob cannot remove pieces from the edge of the line.
If a player cannot make a move on their turn, that player loses and the other player wins.
Assuming Alice and Bob play optimally, return true if Alice wins, or return false if Bob wins.

Constraints:
1 <= colors.length <= 105
colors consists of only the letters 'A' and 'B'

Difficulty: Medium

"""

#Time Complexity:O(n) 
class Solution:
    def winnerOfGame(self, colors: str) -> bool:
        color_table = {"A":0,"B":0}
        length = len(colors)
        if length<3:
            return False
        "Calculate total continuous 3 or more occurence of each string"
        for i in range(length-2):
            if(colors[i]==colors[i+1]==colors[i+2]):
                color_table[colors[i]]+=1
        "Check who runs out first based on the occurence calculated previously"
        if color_table["A"]>color_table["B"]:
            return True
        return False



"Reference to solve the problem: None"