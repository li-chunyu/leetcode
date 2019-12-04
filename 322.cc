# dp[i] 表示达到总数 i 需要的硬币数量。
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
      if (!amount) return 0;
      vector<int> dp(amount+1, -1);
      dp[0] = 0;
      int m = INT_MAX;
      for (int i = 1; i < amount+1; ++i) {
        m = INT_MAX;
        for (auto c : coins) {
          if (i - c >= 0 && dp[i-c] != -1) {
            m = min(m, dp[i-c]+1);
            dp[i] = m;
          }
        }
      }
      return dp[amount];
    }
};