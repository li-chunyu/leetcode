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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nums;
        travel(nums, root);
        return consBST(nums, 0, nums.size());
    }
    void travel(vector<int>& nums, TreeNode* root) {
        if (root == nullptr) return;
        travel(nums, root->left);
        nums.push_back(root->val);
        travel(nums, root->right);
    }
    
    TreeNode* consBST(vector<int>& nums, int i, int j) {
        if (i >= j) return NULL;
        int mid = (i+j) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = consBST(nums, i, mid);
        root->right = consBST(nums, mid+1, j);
        return root;
    }
};