class NumArray {
public:
    NumArray(vector<int>& nums) {
        if (nums.size() != 0){
            tmp = vector<int>(nums.size(), 0);
            tmp[0] = nums[0];
            for (int i = 1; i < nums.size(); ++i)
                tmp[i] = nums[i] + tmp[i-1];
        }
    }
    
    int sumRange(int i, int j) {
        return i == 0? tmp[j]:tmp[j] - tmp[i-1];
    }
    
private:
    vector<int> tmp;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */