class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
      if (board[click[0]][click[1]] == 'M') {
        board[click[0]][click[1]] = 'X';
        return board;
      }
      reveal(board, click[0], click[1]);
      return board;
    }
  
    void reveal(vector<vector<char>>& board, int x, int y) {
      if (!legalPos(board, x, y) || board[x][y] != 'E') return;

      int adjmine = 0;
      for (auto adj : adjs) {
        int xx = x + adj[0], yy = y + adj[1];
        if (legalPos(board, xx, yy) && board[xx][yy] == 'M')
          adjmine++;
      }

      if (adjmine > 0) {
        board[x][y] = '0' + adjmine;
      } else {
        board[x][y] = 'B';
        for (auto adj : adjs) {
          int xx = x + adj[0], yy = y + adj[1];
          reveal(board, xx, yy);
        }
      }
    }
  
    bool legalPos(vector<vector<char>>& board, int x, int y) {
      return (x >= 0 && x < board.size() && y >= 0 && y < board[0].size());
    }
  
  
private:
  vector<vector<int>> adjs{
    {-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
    {0, 1}, {1, -1}, {1, 0}, {1, 1}
  };
};