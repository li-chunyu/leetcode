class Solution {
public:
int helper(vector<int> &nums, int index, int sum, int S, unordered_map<string, int> &map){
		string encodeString = to_string(index) + "->" + to_string(sum);
		if (map.find(encodeString) != map.end()){
				return map[encodeString];
		}
		if (index == nums.size()){
				if (sum == S){
						return 1;
				}else {
						return 0;
				}
		}
		int curNum = nums[index];
		int add = helper(nums, index + 1, sum - curNum, S, map);
		int minus = helper(nums, index + 1, sum + curNum, S, map);
		map[encodeString] = add + minus;
		return add + minus;
}


int findTargetSumWays(vector<int> nums, int S) {
		unordered_map<string, int> map;
		return helper(nums, 0, 0, S, map);
}

};