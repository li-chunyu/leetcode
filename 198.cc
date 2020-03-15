class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int prev = 0, prevprev = 0, res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int cur = max(prev, prevprev+nums[i]);
            res = max(res, cur);
            prevprev = prev;
            prev = cur;
        }
        return res;
    }
};