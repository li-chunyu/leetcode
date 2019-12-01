class Solution {
public:
    bool canJump(vector<int>& nums) {
      if (nums.size() == 0 || nums.size() == 1)
        return true;
      // nearest_aval: 距离当前节点最近的可以抵达目的节点的节点的下标。
      int n = nums.size(), steps = 0, nearest_aval = n-1;
      bool flag = false;
      for (int i = n-2; i >= 0; --i) {
        steps = nums[i];
        flag = false;
        if (steps+i >= nearest_aval) {
          nearest_aval = i;
          flag = true;
        }
      }
      return flag;
    }
};