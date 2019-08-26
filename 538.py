# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def convertBST(self, root: TreeNode) -> TreeNode:
        s = 0
        def recBst(root):
            nonlocal s
            if not root:
                return
            recBst(root.right)
            root.val += s
            s = root.val
            recBst(root.left)
        recBst(root)
        return root