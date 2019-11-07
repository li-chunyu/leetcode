// O(n^2)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      int n = nums.size();
      int s[n+1];
      s[0] = 0;
      int cnt = 0;
      for (int start = 0; start < n; ++start) {
        for (int w = 1; w <= n; ++w) {
          if ((start + w - 1) < n) {
            s[w] = s[w-1] + nums[start+w-1];
            if (s[w] == k)
              cnt++;
          }
        }
      }
      return cnt;
    }
};

// faster O(n)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      unordered_map<int, int> prefix_sum;
      int sum = 0, cnt = 0;
      prefix_sum[0] = 1; // nums[0,0) 即空子数组和为 0，存在这一种情况，
                         // 区别于 nums[0, i), i > 0.
      for(int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        if (prefix_sum.find(sum-k) != prefix_sum.end()) {
          cnt += prefix_sum[sum-k];
        }
        if (prefix_sum.find(sum) != prefix_sum.end()) {
          prefix_sum[sum] += 1;
        } else {
          prefix_sum[sum] = 1;
        }
      }
      return cnt;
    }
};