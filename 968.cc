/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 总体思路为贪心，像父节点返回该节点的角色（0， 1， 2）
class Solution {
public:
    int minCameraCover(TreeNode* root) {
        // 2 不需要父节点照顾，已经被覆盖了或者是空节点
        // 1 可以覆盖父节点的节点，自己覆盖自己
        // 0 需要父节点照顾
        int res = 0;
        int role = dfs(res, root);
        if (role == 0)
            res += 1;
        return res;
    }
    
    int dfs(int& res, TreeNode* root) {
        if (root == nullptr)
            return 2;
        
        int left = dfs(res, root->left);
        int right = dfs(res, root->right);
        if (left == 0 || right == 0) {
            res += 1;
            return 1;
        }
        if (left != 1 && right != 1) {
            // 两个子节点都不能覆盖父节点
            return 0;
        }
        // 至少有一个子节点是1，表示已经被覆盖了
        return 2;
    }
};