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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        recTrans(root, 0, ret);
        return ret;
    }
    
    void recTrans(TreeNode *root, int lev, vector<vector<int>> &ret) {
        if (!root) return;
        if (lev >= ret.size()) {
            ret.push_back(vector<int>(1, root->val));
        } else {
            ret[lev].push_back(root->val);
        }
        recTrans(root->left, lev+1, ret);
        recTrans(root->right, lev+1, ret);
    }
};

/// Non-recursion
/// less memory use
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return vector<vector<int>>();
        deque<pair<TreeNode*, int>> fifo;
        vector<vector<int>> ret;
        fifo.push_back(make_pair(root, 0));
        while (!fifo.empty()) {
            auto p = fifo.front();
            fifo.pop_front();
            if (p.second >= ret.size()) {
                    ret.push_back(vector<int>(1, (p.first)->val));
            } else {
                ret[p.second].push_back((p.first)->val);
            }
            if ((p.first)->left) {
                fifo.push_back(make_pair((p.first)->left, p.second+1));
            }
            if ((p.first)->right) {
                fifo.push_back(make_pair((p.first)->right, p.second+1));
            }
        }
        return ret;
    }
};