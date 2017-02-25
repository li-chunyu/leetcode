/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


/**
 * The essence of this solution is binary tree traversal.
 * During traverse the binary three, if find a node is left
 * leave, then return its value.
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        bool flag = false;
        return sumOfLetLeaves_Recur(root, flag);
    }

    int sumOfLetLeaves_Recur(TreeNode* root, bool isLeftChild){
        if (NULL == root) return 0;
        if (!root->left && !root->right && isLeftChild) {
            return root->val;
        }
        return sumOfLetLeaves_Recur(root->left, true) + sumOfLetLeaves_Recur(root->right, false);
    }
};
