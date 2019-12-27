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
    bool isSubtree(TreeNode* s, TreeNode* t) {
      vector<TreeNode*> nodes;
      travTree(s, nodes);
      for (auto n : nodes) {
        if (identical(n, t))
          return true;
      }
      return false;
    }
    
    void travTree(TreeNode* s, vector<TreeNode*> &nodes) {
      if (s == NULL) return;
      nodes.push_back(s);
      travTree(s->left, nodes);
      travTree(s->right, nodes);
    }
  
    bool identical(TreeNode* s, TreeNode* t) {
      if (!s && !t) return true;
      if (!s || !t) return false;
      return (s->val == t->val) && identical(s->left, t->left) && identical(s->right, t->right);
    }
};