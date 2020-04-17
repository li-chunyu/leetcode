class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() == 1)
            return false;
        sort(nums.begin(), nums.end());
        int slow = 0, fast = 0;
        fast = slow;
        while (slow != nums.size()) {
            while (fast < nums.size() && nums[slow] == nums[fast]) fast++;
            if (fast - slow > 1)
                return true;
            slow = fast;
        }
        return false;
    }
};
