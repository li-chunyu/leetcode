/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return helper(data);
    }
    
    TreeNode* helper(string& data) {
        if (data[0] == '#') {
            if (data.size() > 1) {
                data = data.substr(2);
            }
            return NULL;
        } else {
            TreeNode* node = new TreeNode(dealComma(data));
            node->left = helper(data);
            node->right = helper(data);
            return node;
        }
    }
    
    int dealComma(string& data) {
        int i = 0, res;
        while (data[i++] != ',');
        res = stoi(data.substr(0, i-1));
        data = data.substr(i);
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));