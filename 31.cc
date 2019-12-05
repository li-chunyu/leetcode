class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      if (nums.size() <= 1) return;
      vector<int>::iterator i = nums.end(), ii = nums.end();
      i = i - 2;
      ii = ii - 1;
      while (*i >= *ii) {
        if (i == nums.begin()) {
          reverse(nums.begin(), nums.end());
          return;
        }
        ii = i;
        i--;
      }
      vector<int>::iterator j = nums.end();
      while (!(*i < *--j));
      iter_swap(i, j);
      reverse(ii, nums.end());
      return;
    }
};