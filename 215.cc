class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() == 1) 
            return nums[0];
        int res = 0;
        res = quickFind(nums, 0, nums.size(), k-1);
        return res;
    }
    
    
    int quickFind(vector<int>& nums, int lo, int hi, int target) {
        int j = partition(nums, lo, hi);
        if (j == target) {
            return nums[j];
        }
        if (target > j)
            return quickFind(nums, j+1, hi, target);
        else
            return quickFind(nums, lo, j, target);
    }
    
    int partition(vector<int>& nums, int lo, int hi) {
        int v = nums[lo];
        int i = lo, j = hi;
        while (true) {
            // if nums.size() == 1, 这里 nums[++i]会越界。
			// 这么看算法4 里这里的条件存在越界的风险。
            while (i+1 < hi && nums[++i] > v);
            while (j > lo && nums[--j] < v);
            if (i >= j) break;
            // now, blow must be true:
            //  nums[i] >= nums[lo]
            //  nums[j] <= nums[lo]
            swap(nums[i], nums[j]);
        }
        // now, blow must be true:
        //  nums[i] >= nums[lo]
        //  nums[j] <= nums[lo]
        // so we swap nums[j] and nums[lo], because nums[j] must <= nums[lo].
        swap(nums[lo], nums[j]);
        return j;
    }
};
