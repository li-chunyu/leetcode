class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
      int R = matrix.size();
      if (R == 0) return 0;
      int C = matrix[0].size();
      int dp[R][C];
       int max_edge = 0;
      for (int i = 0; i < C; ++i) {
        if (matrix[0][i] == '1'){
          dp[0][i] = 1;
          max_edge = 1;
        } else {
          dp[0][i] = 0;
        }
      }
      for (int i = 0; i < R; ++i) {
        if (matrix[i][0] == '1') {
          dp[i][0] = 1;
          max_edge = 1;
        } else {
          dp[i][0] = 0;
        }
      }
      for (int r = 1; r < R; ++r) {
        for (int c = 1; c < C; ++c) {
          if (matrix[r][c] == '1'){
            dp[r][c] = min(min(dp[r-1][c], dp[r][c-1]), dp[r-1][c-1]) + 1;
            // cout << dp[r][c] << endl;
            max_edge = max(max_edge, dp[r][c]);
          } else {
            dp[r][c] = 0;
          }
        }
      }
      return max_edge * max_edge;
    }
};