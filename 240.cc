class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int nrow = matrix.size();
      if (nrow == 0) return false;
      int ncol = matrix[0].size();
      int row = 0, col = ncol - 1;
      while (col >= 0 && row < nrow) {
        if (matrix[row][col] == target) {
          return true;
        } else if (matrix[row][col] > target) {
          col -= 1;
        } else {
          row += 1;
        }
      }
      return false;
    }
};