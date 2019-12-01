// very slow version 
// Runtime: 568 ms, faster than 5.07% of C++ online submissions for Word Search.
// Memory Usage: 196.9 MB, less than 14.71% of C++ online submissions for Word Search.


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
      int R = board.size();
      if (R == 0) return false;
      int C = board[0].size();
      for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
          if (word[0] == board[i][j]) {
            vector<vector<bool>> used(R, vector<bool>(C, false));
            used[i][j] = true;
            if (dfs(board, word, 1, used,
                    i, j)) {
              return true;
            }
          }
        }
      }
      return false;
    }
    
  
    bool dfs(vector<vector<char>>& board, string& word,
              int idx, vector<vector<bool>> used,
              int i, int j) {
      if (word.size() == idx)
        return true;
      
      bool flag1 = false, flag2 = false, flag3 = false, flag4 = false;
      if (i != 0 && !used[i-1][j] && board[i-1][j] == word[idx]) {
        used[i-1][j] = true;
        flag1 = dfs(board, word, idx+1, used, i-1, j);
        used[i-1][j] = false;
        if(flag1) return true;
      }
      
      if (i != board.size()-1 && !used[i+1][j] &&
          board[i+1][j] == word[idx]) {
        used[i+1][j] = true;
        flag2 = dfs(board, word, idx+1, used, i+1, j);
        used[i+1][j] = false;
        if (flag2) return true;
      }
      
      if (j != 0 && !used[i][j-1] && board[i][j-1] == word[idx]) {
        used[i][j-1] = true;
        flag3 = dfs(board, word, idx+1, used, i, j-1);
        used[i][j-1] = false;
        if (flag3) return true;
      }
      
      if (j != board[0].size()-1 && !used[i][j+1] &&
          board[i][j+1] == word[idx]) {
        used[i][j+1] = true;
        flag4 = dfs(board, word, idx+1, used, i, j+1);
        used[i][j+1] = false;
        if (flag4) return true;
      }
      return false;
    }
};


// fast imp

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
      int R = board.size();
      if (R == 0) return false;
      int C = board[0].size();
      for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
          if (word[0] == board[i][j]) {
            if (word.size() == 1) {
              return true;
            }
            if (dfs(board, word, 0, i, j)){
              return true;
            }
          }
        }
      }
      return false;
    }
    
  
    bool dfs(vector<vector<char>>& board, string& word,
              int idx, int i, int j) {
      if (i < 0 || i == board.size() || j < 0 || j == board[0].size())
        return false;
      if (word.size() == idx)
        return true;
      if (word[idx] != board[i][j]) return false;
      
      char tmp = board[i][j];
      board[i][j] = '#';
      
      bool r = dfs(board, word, idx+1, i-1, j) ||
        dfs(board, word, idx+1, i+1, j) ||
        dfs(board, word, idx+1, i, j-1) ||
        dfs(board, word, idx+1, i, j+1);
      board[i][j] = tmp;
      return r;
    }
};