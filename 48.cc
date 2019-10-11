/// 原地旋转图片 90 度
/// 观察发现，顺时针旋转图片 90 度等价于，求矩阵的转置,再把每个行向量逆序。
/// For example: a1, a2, a3 均为列向量
///
/// (a1, a2, a3)              | a1.T |                            | rev(a1.T) |
///              ---Trans---> | a2.T | ---reverse_line_vector---> | rev(a2.T) |
///                           | a3.T |                            | rev(a3.T) |


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.size() == 1) return; 
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = i+1; j < matrix.size(); ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < matrix.size(); ++i) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};