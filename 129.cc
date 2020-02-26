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
    int sumNumbers(TreeNode* root) {
        auto nums = numbers(root);
        int sum = 0;
        for (auto n : nums)
            sum += n.first;
        return sum;
    }
  
    vector<pair<int, int>> numbers(TreeNode* root) {
        if (root == NULL) return vector<pair<int, int>>();
        if (root->left == NULL && root->right == NULL)
            return vector<pair<int, int>>(1, make_pair(root->val, 1));
        
        vector<pair<int, int>> right = numbers(root->right);
        vector<pair<int, int>> left = numbers(root->left);
        vector<pair<int, int>> res;
        int digit = root->val;
        for (auto n : right) {
            int number = digit * pow(10, n.second) + n.first;
            res.push_back(make_pair(number, n.second+1));
        }
        for (auto n : left) {
            int number = digit * pow(10, n.second) + n.first;
            res.push_back(make_pair(number, n.second+1));
        }
        return res;
    }
    
    int sizeOfInt(int num) {
        for (int i = 0;;++i) {
            if (num <= sizeTable[i])
                return i+1;
        }
        return 0;
    }
    static int sizeTable[10];
};

int Solution::sizeTable[10] = {9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999, INT_MAX };