class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // O(n^2)
        // T(n) = max(T(i)+1), i is [0, n), if nums[i] < nums[n].
        // O(nlogn)
        
        vector<int> res; // 最长升序子列的最小的末尾元素
        for (int i = 0; i < nums.size(); ++i) {
            // 寻找第一个大于或者等于 Nums[i]的元素
            auto it = lower_bound(res.begin(), res.end(), nums[i]);
            if (it == res.end()) {
                // 如果找不到，说明 nums[i] 是在目前最长升序子列中最大的,加入末尾子列长度+1.
                res.push_back(nums[i]);
            } else {
                // 发现了，如果是 res 的最后一个元素那么更新他，最长子列末尾元素变小
                // 如果不是res 的最后一个元素，也更新他，并不影响结果。
                *it = nums[i];
            }
        }
        return res.size();
    }
};