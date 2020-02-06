#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        bool res;
        res = isSolved(board, 0, 0);
    }
    
    bool isSolved(vector<vector<char>>& board, int i, int j) {
        if (i == 9) return true;
        if (j == 9) return isSolved(board, i+1, 0);
        if (board[i][j] != '.') {
        isSolved(board, i, j+1);
        }
        for (int c = '1'; c <= '9'; ++c) {
            if (isValid(board, i, j, c)) {
                board[i][j] = c;
                if (isSolved(board, i, j+1)) return true;
                // 不能解决数独恢复为 '.'
                board[i][j] = '.';
            }
        }
        return false;
    }
    
    bool isValid(vector<vector<char>>& board, int i, int j, char c) {
        int block_i = i / 3;
        int block_j = j / 3;
        
        for (int ii = 0; ii < 9; ++ii) {
            if (board[ii][j] == c) return false;
            if (board[i][ii] == c) return false;
        }
        
        for (int ii = 0; ii < 3; ++ii) {
            for (int jj = 0; jj < 3; ++jj) {
                char tmp = board[block_i*3+ii][block_j*3+jj];
                if (tmp == c) return false;
            }
        }
        return true;
    }
};


int main() {
  vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
  Solution so;
  so.solveSudoku(board);
  return 0;
}