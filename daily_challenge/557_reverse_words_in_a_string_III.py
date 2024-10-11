"""
Problem Statement:
Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Constraints:
1 <= s.length <= 5 * 104
s contains printable ASCII characters.
s does not contain any leading or trailing spaces.
There is at least one word in s.
All the words in s are separated by a single space.

Difficulty: Easy

"""

#Time Complexity: O(n)
class Solution:
    def reverseWords(self, s: str) -> str:
        #reverse the string
        reversed_string = s[::-1].split(" ")
        #split reversed string by space into list and reverse it to preserve the word alignment of initial sentence. Join those words by space to convert it to string again.
        return " ".join(reversed_string[::-1])


"Reference/Insight used to solve the problem: None"
