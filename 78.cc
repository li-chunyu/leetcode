class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret(1, vector<int>());
        for (auto n: nums) {
            vector<vector<int>> add;
            for (auto subset : ret) {
                subset.push_back(n);
                add.push_back(subset);
            }
            ret.insert(ret.end(), add.begin(), add.end());
        } 
        return ret;
    }
};