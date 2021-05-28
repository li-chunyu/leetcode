class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
 		int max_piles = 0;
		for (auto p : piles) max_piles = max(p, max_piles);
		int left = 1, right = max_piles;
		int res = INT_MAX;
		while (left <= right) {
			int k = (left + right) / 2, h_needed = 0;
			for (auto p : piles) {
				h_needed += p / k;
				if (p % k != 0) h_needed += 1;
			}
			if (h_needed <= h) {
				right = k - 1;
				res = min(res, k);
			} else {
				left = k + 1;
			}
		}
		return res;
    }
};
