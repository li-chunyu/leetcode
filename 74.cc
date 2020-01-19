// 把 Matrix 当成一个 vector (colum wise).

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        int R = matrix.size(), C = matrix[0].size();
        int n = R * C;
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r) / 2;
            auto dim = v2m(mid, C);
            if (matrix[dim.first][dim.second] == target) {
                return true;
            } else if (matrix[dim.first][dim.second] < target){
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return false;
    }
    
    inline pair<int, int> v2m(int v, int C) {
        return make_pair(v/C, v%C);
    }
};