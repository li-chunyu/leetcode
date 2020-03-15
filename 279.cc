class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            int perfect_square = 0;
            for (int j = 1; (perfect_square = j*j) <= i; ++j) {
                dp[i] = min(dp[i], 1+dp[i-perfect_square]);
            }
        }
        return dp[n];
    }
};