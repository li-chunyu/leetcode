//  \ref https://leetcode.com/problems/partition-to-k-equal-sum-subsets/discuss/108730/JavaC%2B%2BStraightforward-dfs-solution


class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (auto n : nums)
            sum += n;
        if (sum % k != 0) return false;
        vector<bool> visited(nums.size(), false);
        return canPartition(nums, visited, k, sum/k, 0, 0, 0);
    }
    
    bool canPartition(vector<int>& nums, vector<bool>& visited,
                      int k, int target, int cur_sum, int index, int cur_n) {
        if (k == 1) return true;
        if (target == cur_sum && cur_n != 0)
            // 开始新的 subset 搜索，所以这里把 index 设为0， 从头开始搜索 
            return canPartition(nums, visited, k-1, target, 0, 0, 0);
        // index的作用： 这个 for 循环的作用是搜索每个没有被 visited 的数字加入到
        //  当前 subset 中是否能够满足要求。index 之前的数字加入到当前 subset 中的
        //  可能性已经搜索过了，所以应该避免继续搜索(因为subset 中数字的顺序是无所谓的)。
        //  比如 for 循环进行到 i = n, 说明 i < n 的情况时 canPartition 都返回的是 false
        //  ，所以 nums[j], j < n 都不能加入到当前 subset，就不需要进行重复搜索，只需要从 n + 1开始
        //  搜索nums[n+1...nums.size()]加入到当前 subset能否满足要求  。
        //  （并没有解释太清楚，需要结合代码好好理解一下 inde 的作用）
        for (int i = index; i < nums.size(); ++i) {
            if (!visited[i]) {
                visited[i] = true;
                if (canPartition(nums, visited, k, target,
                                 cur_sum+nums[i], i+1, cur_n+1))
                    return true;
                visited[i] = false;
            }
        }
        return false;
    }
};