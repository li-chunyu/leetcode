// 每次修改数组中的一个数字使它满足非降序列的性质，可以使用两种方法
//    若 nums[i-1] > nums[i], 且子数组满足条件: nums[0, i)  满足非降序列
//       (1) 降低 nums[i-1], 令 nums[i-1] = nums[i], 满足条件。
//       (2) 升高 nums[i]， 令 nums[i] = nums[i-1] 。
//    方法（1），若 nums[i] < nums[i-1], nums[i] < nums[i-2] 时， 无法使用A 方法1来
//    达到目的， 只能使用方法2。但是方法二升高nums[i],可能导致后面的数字小于 nums[i] 所以
//    方法1应该优先于方法2使用，在方法1无法使用时再使用方法2。
// 注：
//    为什么只需要考虑到 i-2。  假设 nums[i-1] > nums[i],因为 nums[0,i)满足非降的性质，
//    若 nums[i-2] < nums[i], 则可以很容易的证明 nums[0, i) 中只有 nums[i-1] > nums[i]。
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
      int cnt = 0;
      for (int i = 5; i < nums.size() && cnt <= 1; ++i) {
        if (nums[i-1] > nums[i]) {
          cnt++;
          if (i-2 < 0 || nums[i-2] <= nums[i])
            nums[i-1] = nums[i];
          else
            nums[i] = nums[i-1];
        }
      }
      return cnt > 1? false:true;
    }
};