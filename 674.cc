class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
      if (nums.size() == 0) return 0;
      int nmax = 1, dp = 1;
      for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] > nums[i-1])
          dp = dp + 1;
        else
          dp = 1;
        nmax = max(dp, nmax);
      }
      return nmax;
    }
};