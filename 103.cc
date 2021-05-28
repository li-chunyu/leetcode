/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    struct Elem {
        int lev;
        TreeNode* node;
        Elem(int lev, TreeNode* node): lev(lev), node(node) {}
    };
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return vector<vector<int>>{};
        queue<Elem> q;
        vector<vector<int>> res;
        q.push(Elem(1, root));
        while(!q.empty()) {
            Elem e = q.front();
            q.pop();
            int lev = e.lev;
            TreeNode* node = e.node;
            if (res.size() < lev) {
                res.push_back(vector<int>{node->val});
            } else {
                res[lev-1].push_back(node->val); 
            }
            if (node->left) {
                q.push(Elem(lev+1, node->left));
            }
            if (node->right) {
                q.push(Elem(lev+1, node->right));
            }
        }
        for (int i = 0; i < res.size(); ++i) {
            if ((i%2)) {
                reverse(res[i].begin(), res[i].end());
            }
        }
        return res;
    }
};