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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
      if (!root)
        return NULL;
      if (root->val < L) {
        return trimBST(root->right, L, R);
      } else if (root->val > R) {
        return trimBST(root->left, L, R);
      } else {
        root->left = trimBST(root->left, L, root->val);
        root->right = trimBST(root->right, root->val, R);
        return root;
      }
      // should never be here.
      return NULL;
    }
};