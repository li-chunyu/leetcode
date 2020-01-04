    struct TrieNode {
        int val;
        TrieNode* right; // zero
        TrieNode* left; // one
        TrieNode(int v): val(v), right(NULL), left(NULL){}
    };
    
    int findMaximumXOR(vector<int>& nums) {
        // construct Trie tree.
        TrieNode* root = new TrieNode(0); // always positive.
        for (int i = 0; i < nums.size(); ++i) {
            TrieNode* cur = root;
            for (int b = 31; b >= 0; --b) {
                int bitmask = 1;
                bitmask = bitmask << b;
                if (nums[i] & bitmask) {
                    if (!cur->left)
                        cur->left = new TrieNode(1);
                    cur = cur->left;
                } else {
                    if (!cur->right)
                        cur->right = new TrieNode(0);
                    cur = cur->right;
                }
            }
        }

        int max = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int res = 0;
            TrieNode* cur = root;
            for (int j = 31; j >= 0; --j) {
                int curbit = nums[i] & (1 << j);
                if (cur->left && cur ->right) {
                    if (curbit)
                        cur = cur->right;
                    else
                        cur = cur->left;
                } else {
                    cur = cur->left == NULL?cur->right:cur->left;
                }
                res += curbit ^ (cur->val << j);
            }
            max = res > max?res:max;
        }
        return max;
    }
};