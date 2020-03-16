class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int R = matrix.size(), C = matrix[0].size();
        vector<int> row(R, INT_MAX); // min
        unordered_map<int, int> m;
        vector<int> col(C, INT_MIN); // max
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                row[i] = min(row[i], matrix[i][j]);
                col[j] = max(col[j], matrix[i][j]);
            }
        }
        for (int i = 0; i < R; ++i) {
            m[row[i]] = 1;
        }
        vector<int> res;
        
        for (int i = 0; i < C; ++i) {
            if (m.find(col[i]) != m.end())
                res.push_back(col[i]);
        }

        return res;
    }
};