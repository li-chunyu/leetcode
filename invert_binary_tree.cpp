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
    TreeNode* invertTree(TreeNode* root) {

  		if (root == NULL || (root->left==NULL && root->right==NULL) ) {
  			return root;
  		}

  		// Exchange child trees.
  		TreeNode* temp = NULL;
  		temp = root->left;
  		root->left = root->right;
  		root->right = temp;

  		invertTree(root->right);
  		invertTree(root->left);

  		return root;
  			
    }
};
