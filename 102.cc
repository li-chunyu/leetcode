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
               
        vector<vector<int>> res;
        queue<pair<int, TreeNode*>> q;
        q.push(make_pair(0, root));
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            
            int index = p.first;
            TreeNode *cur = p.second;
            if (cur == NULL) continue;
            //  这个条件改为 index > res.size() - 1 就不能正常运行，
            // index > res.size() - 1在逻辑上是正确的（index 大于 res 数组最大的可访问的下标），
            // 但是 STL vector size()方法返回值为 size_t 是一个 unsigned int, 如果 size()的返回值
            // 为0 ,用 0 (unsigned int) 减 1，会造成数值下溢，导致 size()-1变成一个非常大的数，
            // 所以使用这个条件不能 work。
            if (index >= res.size())
                res.push_back(vector<int>());
            res[index].push_back(cur->val);
            q.push(make_pair(index+1, cur->left));
            q.push(make_pair(index+1, cur->right));
        }
        return res;
    }
};








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