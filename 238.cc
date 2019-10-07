class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret(nums.size(), 1);
        int left = 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0)
                left *= nums[i-1];
            ret[i] = left;
        }
        int right = 1;
        for (int i = nums.size()-1; i >= 0; --i) {
            if (i < nums.size()-1)
                right *= nums[i+1];
            ret[i] *= right; 
        }
        return ret;
    }
};