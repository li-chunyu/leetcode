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
    struct Object {
        bool valid;
        int maxVal;
        int minVal;
        bool isNULL; // 为了应对 root->val = INT_MAX 或者 root->val = INT_MIN 的情况。
        Object(bool a, int b, int c): valid(a), maxVal(b), minVal(c){}
    };
    
    bool isValidBST(TreeNode* root) {
        Object *obj = helper(root);
        return obj->valid;
    }
    
    Object* helper(TreeNode* root) {
        if (root == NULL) {
            Object *ret = new Object(true, INT_MIN, INT_MAX);
            ret->isNULL = true;
            return ret;
        }
        
        Object *leftobj = helper(root->left);
        Object *rightobj = helper(root->right);
        if (leftobj->valid == false || rightobj->valid == false)
            return new Object(false, INT_MIN, INT_MAX);
        
        bool leftcond = leftobj->isNULL? true: root->val > leftobj->maxVal;
        bool rightcond = rightobj->isNULL? true: root->val < rightobj->minVal;
        Object *ret;
        if (leftcond && rightcond) {
            int ma = rightobj->isNULL? root->val: rightobj->maxVal;
            int mi = leftobj->isNULL? root->val: leftobj->minVal;
            ret = new Object(true, max(root->val, ma), min(root->val, mi));
            ret->isNULL = false;
        } else {
            ret = new Object(false, 1, 1);
            ret->isNULL = false;
        }
            
        return ret;
    }
};