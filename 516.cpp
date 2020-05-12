class Solution {
public:
    int longestPalindromeSubseq(string s) {
        /*
        dp[len][index] = (j = len + index) if s[index] == s[j] dp[len][index] += dp[len-1][index+1] + 2
                                           if s[index] != s[j] dp[len][index] = max(dp[len-1][index], dp[len-1][index+1])
        */
                                             
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }
        for (int l = 1; l < n; ++l) {
            for (int i = 0; i < n-l; ++i) {
                int j = i + l;
                if (s[i] == s[j]) {
                    dp[i][j] = (l == 1? 2 : dp[i+1][j-1] + 2);
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};
