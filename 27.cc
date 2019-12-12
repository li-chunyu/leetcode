class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
      if (nums.size() == 0) return 0;
      int left = -1, right = nums.size();
      while (left < right) {
        while (--right >= 0 && nums[right] == val);
        while (++left < nums.size() && nums[left] != val);
        if (right >=0 && left < nums.size() &&
            nums[left] == val && left < right)
          swap(nums[right], nums[left]);
      }
      return right+1;
    }
};
