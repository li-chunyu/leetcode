class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        int nshortest = 0;
        while (left < nums.size()-1 && nums[left] <= nums[left+1]) left++;
        while (right > 0 && nums[right] >= nums[right-1]) right--;
        
        if (left < right) {
            int max = INT_MIN, min = INT_MAX;
            for (int i = left; i <= right; ++i) {
                if (nums[i] > max) max = nums[i];
                if (nums[i] < min) min = nums[i];
            }
            while (left>=0 && nums[left]>min) left--; 
            while (right<=nums.size()-1 && nums[right]<max) right++;
            nshortest = right - left - 1;
        }
        return nshortest;
    }
};
