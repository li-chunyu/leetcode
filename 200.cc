/// union find

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
      int r = grid.size();
      if (r == 0)
        return 0;
      int c = grid[0].size();
      vector<int> ids(r*c, 1);
      for (int i = 0; i < ids.size(); ++i) {
        ids[i] = i;
      }
      for (int row = 0; row < r; ++row) {
        for (int col = 0; col < c; ++col) {
          if (grid[row][col] == '0') continue;
          if (row != 0 && grid[row-1][col] == '1') 
            uni(ids, row*c+col, (row-1)*c+col);
          if (row < r-1 && grid[row+1][col] == '1') 
            uni(ids, row*c+col, (row+1)*c+col);
          if (col != 0 && grid[row][col-1] == '1')
            uni(ids, row*c+col, row*c+col-1);
          if (col < c-1 && grid[row][col+1] == '1')
            uni(ids, row*c+col, row*c+col+1);
        }
      }
      int ret = 0;
      for (int row = 0; row < r; ++row) {
        for (int col = 0; col < c; ++col) {
          if (grid[row][col] == '1' && ids[row*c+col] == row*c+col)
            ret += 1;
        }
      }
      
      return ret;
    }
      
    int find(vector<int> &ids, int id) {
      while (ids[id] != id) id = ids[id];
      return id;
    }

    void uni(vector<int> &ids, int id1, int id2) {
      int root1 = find(ids, id1);
      int root2 = find(ids, id2);
      if (root1 == root2) return;
      ids[root1] = root2;
    }
};