class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if (row == 0) return 0;
        int col = matrix[0].size();
        
        vector<int> l(col, 0);
        vector<int> r(col, col);
        vector<int> h(col, 0);
        int res = 0;
        for (int i = 0; i < row; ++i) {
            int left_continuous_ones = 0;
            int right_continuous_ones = col;
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == '1') {
                    l[j] = max(l[j], left_continuous_ones);
                } else {
                    // matrix[i][j] = '0' => h[j] = 0 => 面积恒为0，底长无所谓
                    // right 同理
                    l[j] = 0;
                    left_continuous_ones = j+1;
                }
            }
            
            for (int j = col-1; j >=0; --j) {
                if (matrix[i][j] == '1') {
                    r[j] = min(r[j], right_continuous_ones);
                } else {
                    r[j] = col; // 此处 height == 0
                    right_continuous_ones = j;
                }
            }
            
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == '1') {
                    h[j] = h[j] + 1;
                } else {
                    h[j] = 0;
                }
            }
            for (int j = 0; j < col; ++j)
                res = max(res, (r[j] - l[j]) * h[j]);
        }
        return res;
    }
};