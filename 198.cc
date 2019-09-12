class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() <= 2) {
            return nums.size() == 1? nums[0]:max(nums[0], nums[1]);
        }
        vector<int> rob(nums.size(), 0);
        rob[0] = nums[0];
        rob[1] = max(nums[0], nums[1]);
        int maxrob = max(rob[0], rob[1]);
        for (int i = 2; i < nums.size(); ++i) {
            rob[i] = max(rob[i-2]+nums[i], rob[i-1]); 
            if (rob[i] > maxrob) {
                maxrob = rob[i];
            }
        }
        return maxrob; 
    }
};