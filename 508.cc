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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> umap;
        getSums(root, umap);
        vector<int> res;
        int freq = 0;
        for (auto p : umap) {
            if (p.second > freq) {
                freq = p.second;
                res = vector<int>(1, p.first);
            } else if (p.second == freq) {
                res.push_back(p.first);
            }
        }
        return res;
    }
    
    int getSums(TreeNode* root, unordered_map<int, int>& umap) {
        if (root == NULL)
            return 0;
        int sum = root->val + getSums(root->left, umap) + getSums(root->right, umap);
        if (umap.find(sum) != umap.end())
            umap[sum] += 1;
        else
            umap[sum] = 1;
        return sum;
    }
};