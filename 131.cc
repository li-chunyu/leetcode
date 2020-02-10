class Solution {
public:
    vector<vector<string>> partition(string s) {
        if (s.size() == 0) return vector<vector<string>>();
        
        int idx = 0;
        vector<vector<string>> res;
        helper(s, res, vector<string>(), 0);
        return res;
    }
    
    void helper(string& s, vector<vector<string>>& res, vector<string> partition, int idx) {
        if (idx == s.size()) {
            res.push_back(partition);
            return;
        }
        for (int i = idx+1; i <= s.size(); ++i) {
            if (isPalindrome(s, idx, i)) {
                partition.push_back(s.substr(idx, i-idx));
                helper(s, res, partition, i);
                partition.pop_back();
            }
        }
    }
    
    bool isPalindrome(string& s, int start, int end) {
        int l = start, r = end-1;
        while (l <= r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};