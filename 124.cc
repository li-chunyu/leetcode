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
    int maxPathSum(TreeNode* root) {
        int max_path = INT_MIN;
        maxSumPassTheNode(root, max_path);
        return max_path;
    }
    
    int maxSumPassTheNode(TreeNode* root,int& max_path) {
        if (!root) return 0;
        int left_max = maxSumPassTheNode(root->left, max_path);
        int right_max = maxSumPassTheNode(root->right, max_path);
        if (left_max < 0) left_max = 0;
        if (right_max < 0) right_max = 0;
        if (left_max + right_max + root->val > max_path)
            max_path = left_max + right_max + root->val;

        // 如果 maxpath 包括了 root，root->left, root->right 三者之和,
        // 那么该 maxpath 就不能给 root 的父节点复用，因为这样不构成一个路径
        // 所以只返回给 root 的父节点 root + root->left 或者 root + root->right。
        return root->val + max(left_max, right_max);
    }
};