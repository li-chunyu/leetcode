\class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int R = board.size();
        if (R == 0) return false;
        int C = board[0].size();
        
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                if (board[r][c] == word[0]) {
                    if (word.size() == 1)  return true;
                    vector<vector<bool>> used(R, vector<bool>(C, false));
                    if (isExist(board, used, r, c, word, 0)) return true;
                }
            }
        }
        return false;
    }
    
    bool isExist(vector<vector<char>>& board, vector<vector<bool>>& used,
                 int i, int j, string& word, int n) {
        if (n == word.size()) return true;
        if (i == board.size() || i < 0) return false;
        if (j == board[0].size() || j < 0) return false;
        if (used[i][j]) return false;
        
        if (board[i][j] != word[n]) return false;
        
        used[i][j] = true;
        if (   isExist(board, used, i-1, j, word, n+1) ||
               isExist(board, used, i+1, j, word, n+1) ||
               isExist(board, used, i, j-1, word, n+1) ||
               isExist(board, used, i, j+1, word, n+1)   ) {
            return true;
        }
        used[i][j] = false;
        return false;
    }
};