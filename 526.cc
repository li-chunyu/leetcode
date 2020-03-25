class Solution {
public:
    int countArrangement(int N) {
        int res = 0;
        vector<bool> used(N+1, false);
        backtracking(used, 1, res);
        return res;
    }
    
    void backtracking(vector<bool>& used, int index, int& res) {
        if (index == used.size()) {
            res++;
            return;
        }
            
        for (int i = 1; i < used.size(); ++i) {
            if (!used[i] && ((i%index == 0) || (index % i) == 0)) {
                used[i] = true;
                backtracking(used, index+1, res);
                used[i] = false;
            }
        }
    }
};
