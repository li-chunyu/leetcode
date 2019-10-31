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
    void flatten(TreeNode* root) {
        stack<TreeNode*> s;
        while (!s.empty() || (root != NULL && (root->left != NULL || root->right != NULL))) {
            if (root->left != NULL && root->right == NULL){
                root->right = root->left;
                root->left = NULL;
            } else if (root->left != NULL && root->right != NULL) {
                s.push(root->right);
                root->right = root->left;
                root->left = NULL;
            } else if (root->left == NULL && root->right == NULL) {
                TreeNode *node = s.top();
                s.pop();
                root->right = node;
            }
            root = root->right;
        }
    }
};