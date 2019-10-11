class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;    
        rec_combination_sum(candidates, target, vector<int>(), ret, 0);
        return ret;
    }
     
    void rec_combination_sum(vector<int>& candidates, int target, vector<int> partial_resualt, vector<vector<int>>& ret, int idx) {
        if (target == 0) {
            sort(partial_resualt.begin(), partial_resualt.end());
            ret.push_back(partial_resualt);
            return;
        }
        if (target < 0) {
            return;
        }
        for (int i = idx; i < candidates.size(); ++i) {
            partial_resualt.push_back(candidates[i]);
            rec_combination_sum(candidates, target-candidates[i], partial_resualt, ret, i);
            partial_resualt.pop_back();
        }
    } 
    
};