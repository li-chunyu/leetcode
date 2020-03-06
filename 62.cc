class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp = vector<vector<int>>(m, vector<int>(n, 0));
        // dp[0][0] = 1;
        for (int i = 0; i < n; ++i)
            dp[0][i] = 1;
        for (int i = 0; i < m; ++i)
            dp[i][0] = 1;
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                int down = get(dp, i-1, j, m, n);
                int right = get(dp, i, j-1, m, n);
                dp[i][j] = down + right;
            }
        }
        return dp[m-1][n-1];
    }
    
    int get(vector<vector<int>>& dp, int i, int j, int m, int n) {
        if (i < 0 || i > m-1 || j <0 || j > n-1)
            return 0;
        else
            return dp[i][j];
    }
};