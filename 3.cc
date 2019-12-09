class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      if (s.size() == 0) return 0;
      int dp = 1, ret = 1, j = 0, low_bound = 0;
      for (int i = 1; i < s.size(); ++i) {
        j = 0;
        low_bound = i - dp;
        while ((i-1-j) >= low_bound &&
               s[i-1-j] != s[i] &&
               ++j);
        dp = j+1;
        ret = max(dp, ret);
      }
      return ret;
    }
};