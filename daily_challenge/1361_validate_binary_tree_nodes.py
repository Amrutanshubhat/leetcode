"""
Problem Statement:
You have n binary tree nodes numbered from 0 to n - 1 where node i has two children leftChild[i] and rightChild[i], return true if and only if all the given nodes form exactly one valid binary tree.

If node i has no left child then leftChild[i] will equal -1, similarly for the right child.

Note that the nodes have no values and that we only use the node numbers in this problem.

Constraints:
n == leftChild.length == rightChild.length
1 <= n <= 104
-1 <= leftChild[i], rightChild[i] <= n - 1


Difficulty: Medium

"""

#Time Complexity: O(n)
class Solution(object):
    def validateBinaryTreeNodes(self, n, leftChild, rightChild):
        """
        :type n: int
        :type leftChild: List[int]
        :type rightChild: List[int]
        :rtype: bool
        """
        def find_root():
            children = set(leftChild) | set(rightChild)
            
            for i in range(n):
                if i not in children:
                    return i
                
            return -1
        
        root = find_root()
        if root == -1:
            return False
        
        seen = {root}
        stack = [root]
        while stack:
            node = stack.pop()
            for child in [leftChild[node], rightChild[node]]:
                if child != -1:
                    if child in seen:
                        return False
                    
                    stack.append(child)
                    seen.add(child)
        
        return len(seen) == n

"Reference/Insight used to solve the problem: https://leetcode.com/problems/validate-binary-tree-nodes/editorial/"