class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int mid = 0;
        return rec(preorder, inorder, mid, 0, preorder.size());
    }
    
    TreeNode* rec(vector<int>& preorder, vector<int>& inorder, int &mid, int l, int r) {
        if (l == r  || mid == preorder.size())
            return NULL;
        TreeNode *root = new TreeNode(preorder[mid]);
        auto it = find(inorder.begin()+l, inorder.begin()+r, preorder[mid]);
        int index = it - inorder.begin();
        mid++;
        root->left = rec(preorder, inorder, mid, l, index);
        root->right = rec(preorder, inorder, mid, index+1, r);
        return root;
    }
};