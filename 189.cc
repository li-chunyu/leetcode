class Solution {
public:
    void rotate(vector<int>& nums, int k) {
		if (nums.size() == 0) return;
		k %= nums.size();
		
		auto it_begin = nums.begin();
		auto it_mid = nums.begin() + (nums.size() - k);
		auto it_end = nums.end();

		reverse(it_begin, it_mid);
		reverse(it_mid, it_end);
		reverse(it_begin, it_end);
    }
};
