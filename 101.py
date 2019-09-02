# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        def is_sym(t1, t2):
            if t1 == None and t2 == None:
                return True
            elif t1 == None or t2 == None:
                return False
            elif t1.val == t2.val:
                return is_sym(t1.left, t2.right) and is_sym(t1.right, t2.left)
            return False
        if root == None:
            return True
        return is_sym(root.left, root.right)
                