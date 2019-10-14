class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[n][m];
        for (int i = 0; i < n; ++i) {
            dp[i][0] = 1;
        }
        for (int row = 0; row < n; ++row) {
            for (int col = 1; col < m; ++col) {
                int from_left = 0;
                int from_up = 0;
                if (row != 0)
                    from_up = dp[row-1][col];
                if (col != 0)
                    from_left = dp[row][col-1];
                dp[row][col] = from_up + from_left;
            }
        }
        return dp[n-1][m-1];
    }
};