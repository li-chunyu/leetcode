class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() == 1)
            return nums[0];
        return partition(nums, 0, nums.size(), k);
    }
    
    int partition(vector<int> &nums, int left, int right, int k) {
        if (left == right || right - left == 1) {
            return nums[left];
        }
        int lo = left, hi = right;
        int key = nums[lo];
        while (true) {
            while (nums[++lo] > key) if (lo == right-1) break;
            while (nums[--hi] < key) if (hi == left) break;
            if (lo >= hi)
                break;
            else
                swap(nums[lo], nums[hi]);
        }
        swap(nums[hi], nums[left]);
        if (hi == k-1) {
            return nums[hi];
        } else if (hi < k-1) {
            return partition(nums, hi+1, right, k);
        } else {
            return partition(nums, left, hi, k);
        }
            
    }
};