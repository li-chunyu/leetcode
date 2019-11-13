class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      if (nums.size() == 0) {
        return 0;
      }
      int dp[nums.size()];
      for (int i = 0; i < nums.size(); ++i) {
        dp[i] = 1;
      }
      for (int i = 1; i < nums.size(); ++i) {
        for (int j = 0; j < i; ++j) {
          if (nums[i] > nums[j]){
            dp[i] = max(dp[j]+1, dp[i]);
          }
        }
      }
      int ret = 0;
      for (int i = 0; i < nums.size(); ++i) {
        ret = max(ret, dp[i]);
      }
      return ret;
    }
};