class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
	vector<int> result;
	vector<int> ord_nums = vector<int>(nums);
	sort(ord_nums.begin(), ord_nums.end());

	int l = 0;
	int r = ord_nums.size() - 1;

	while(l <= r ){
		if((ord_nums[l]+ord_nums[r]) == target){
			for(int i = 0; i<=nums.size(); ++i){
			    if(nums[i]==ord_nums[r] || nums[i]==ord_nums[l] ){
			        result.push_back(i);
			    }
			    if(result.size() == 2)
			        return result;
			}
		}
		if((ord_nums[l]+ord_nums[r]) > target)
		    r--;
		if((ord_nums[l]+ord_nums[r]) < target)
		    l++;
	}
	return result;
    }
};
