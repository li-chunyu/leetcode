# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    max = 0
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        m = 0
        def maxDepth(root):
            nonlocal m
            if not root:
                return 0
            left = maxDepth(root.left)
            right = maxDepth(root.right)
            m = max(left + right, m)
            return max(left, right) + 1
        maxDepth(root)
        return m