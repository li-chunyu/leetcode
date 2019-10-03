/// dp soluiton
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), cnt = 0;
        bool p[n][n] = {false};
        for (int i = n-1; i >=0; --i) {
            for (int j = i; j < n; ++j) {
                p[i][j] = s[i] == s[j] & ((j-i <= 2) || p[i+1][j-1]);
                if (p[i][j]) cnt++;
            }
        }
        return cnt;
    }
};

/// Non-dp solution, faster, space complexity O(1)
class Solution {
public:
    int cnt = 0;
    int countSubstrings(string s) {
        cnt = 0;
        if (s.size() == 0 || s.size() == 1) {
            return 1;
        }
        for (int i = 0; i < s.size(); ++i) {
            extentSubstring(s, i, i);
            extentSubstring(s, i, i+1);
        }
        return cnt;
    }
    void extentSubstring(string &s, int i, int j) {
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            i--; j++;
            cnt++;
        }
    }
};