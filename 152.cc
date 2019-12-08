class Solution {
public:
    int maxProduct(vector<int>& nums) {
      if (nums.size() == 0) return 0;
      if (nums.size() == 1) return nums[0];
      int max_dp, min_dp, ret, pre_max, pre_min;
      max_dp = min_dp = nums[0];
      ret = max_dp; 
      for (int i = 1; i < nums.size(); ++i) {
        pre_max = max_dp;
        pre_min = min_dp;
        max_dp = max(nums[i], max(nums[i]*pre_max, nums[i]*pre_min));
        min_dp = min(nums[i], min(nums[i]*pre_max, nums[i]*pre_min));
        ret = max(ret, max_dp);
      }
      return ret;
    }
};