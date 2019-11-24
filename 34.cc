/// 来自STL的lower_bond 和 upper_bound;
/// 
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      if (nums.size() == 0) {
        return vector<int>{-1, -1};
      }
      int left = left_bound(nums, target);
      if (left == nums.size() || nums[left] != target) {
        return vector<int>{-1, -1};
      }
      int right = right_bound(nums, target);
      return vector<int>{left, right-1};
    }
  
    int left_bound(vector<int>& nums, int target) {
      int len = nums.size();
      int first = 0;
      int half, mid;
      while (len > 0) {
        half = len >> 1;
        mid = first + half;
        if (nums[mid] < target) {
          first = mid + 1;
          len = len - half - 1;
        } else {
          len = half;
        }
      }
      return first;
    }
  
    int right_bound(vector<int>& nums, int target) {
      int len = nums.size();
      int first = 0;
      int half, mid;
      while (len > 0) {
        half = len >> 1;
        mid = first + half;
        if (target < nums[mid]) {
          len = half;
        } else {
          first = mid + 1;
          len = len - half - 1;
        }
      }
      return first;
    }
};