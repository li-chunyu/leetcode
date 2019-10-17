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
    int rob(TreeNode* root) {
        auto p = _rob(root);
        return max(p.first, p.second);
    }
    /// pair.first: root un-robbered.
    /// pair.second: root robbered.
    pair<int, int> _rob(TreeNode* root) {
        if (!root) return make_pair(0,0);
        
        auto left = _rob(root->left);
        auto right = _rob(root->right);
        int unrobed = max(left.first, left.second) + max(right.first, right.second);
        int robed = root->val + left.first + right.first;
        return make_pair(unrobed, robed);
    }
};