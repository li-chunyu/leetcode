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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 /*
  BFS solution
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        
        if (NULL == root) {
            return root;
        }

        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* temp_node = q.front();
            q.pop();
            
            if (NULL != temp_node->left) {
                q.push(temp_node->left);
            }
            
            if (NULL != temp_node->right) {
                q.push(temp_node->right);
            }
            
            TreeNode* temp = temp_node->left;       /* exchange left child tree and right tree */
            temp_node->left = temp_node->right;
            temp_node->right = temp;
        }
        
  		return root;	
    }
};
