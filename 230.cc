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
    int kthSmallest(TreeNode* root, int k) {
        int res = 0, cnt = 0;
        helper(root, cnt, k, res);
        return res;
    }
    
    void helper(TreeNode* root, int& count, int k, int& res) {
        if (root == NULL) return;
        helper(root->left, count, k, res);
        count++;
        if (count == k) {
            res = root->val;
            return;
        }
        helper(root->right, count, k, res);
    }
};