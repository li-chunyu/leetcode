/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int root_index = 0;
        return consBST(preorder, 0, preorder.size());
    }
    // 8,5,1,7,10,12
    TreeNode* consBST(vector<int>& preorder, int lo, int hi) {
        if (lo >= hi)
            return NULL;
        int value = preorder[lo];
        TreeNode* root = new TreeNode(value);
        int mid_index = lo + 1;
        while (mid_index < hi && value > preorder[mid_index]) mid_index++;
        root->left = consBST(preorder, lo+1, mid_index);
        root->right  consBST(preorder, mid_index, hi);
        return root;
    }
};=
