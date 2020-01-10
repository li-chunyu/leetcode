// \ref https://leetcode.com/problems/contiguous-array/discuss/99655/Python-O(n)-Solution-with-Visual-Explanation

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
      unordered_map<int, int> m;
      m[0] = 0;
      int count = 0, res = 0;
      for (int i = 1; i <= nums.size(); ++i) {
        count = nums[i-1] == 0?count-1:count+1;
        if (m.find(count) != m.end()) {
          res = max(res, i-m[count]);
        } else {
          m[count] = i;
        }
      }
      return res;
    }
};