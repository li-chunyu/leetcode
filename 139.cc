class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        s = " " + s;
        vector<bool> dp(s.size(), false);
        dp[0] = true;
        for (int i = 1; i < dp.size(); ++i) {
            for (auto w : wordDict) {
                if (w.size() <= i && s.substr(i-w.size()+1, w.size()) == w){
                    dp[i] = dp[i-w.size()];
                    if (dp[i]) break;
                }
            }
        }
        return dp[dp.size() - 1];
    }
};