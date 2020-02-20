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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> stkp;
        stack<TreeNode*> stkq;
        while (p || q || !stkp.empty() || !stkq.empty()) {
            if (stkp.size() != stkq.size()) return false;
            if ((p == NULL && q != NULL) || (p != NULL && q == NULL))
                return false;
            if (p && q) {
                if (p->val != q->val) return false;
                stkp.push(p->right);
                stkq.push(q->right);
                p = p->left;
                q = q->left;
            } else {
                // if (stkp.size() != stkq.size())
                p = stkp.top();
                stkp.pop();
                q = stkq.top();
                stkq.pop();
            }
        }
        return true;
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
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> stkp;
        stack<TreeNode*> stkq;
        while (p || q || (!stkp.empty() && !stkq.empty())) {
            // if (stkp.size() != stkq.size()) return false;
            if ((p == NULL && q != NULL) || (p != NULL && q == NULL))
                return false;
            if (p && q) {
                if (p->val != q->val) return false;
                stkp.push(p->right);
                stkq.push(q->right);
                p = p->left;
                q = q->left;
            } else {
                // if (stkp.size() != stkq.size())
                p = stkp.top();
                stkp.pop();
                q = stkq.top();
                stkq.pop();
            }
        }
        return stkp.size() == stkq.size();
    }
};