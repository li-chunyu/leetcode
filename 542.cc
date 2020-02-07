// 从每个为 0 的位置开始广度优先更新举例， 不需要更新时收敛


class Solution {
public:
    struct Pos {
        int col;
        int row;
        Pos(int r, int c): row(r), col(c) {}
    };
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int R = matrix.size();
        int C = matrix[0].size();
        queue<Pos> q;
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                if (matrix[r][c] == 0) {
                    q.push(Pos(r, c));
                } else {
                    matrix[r][c] = INT_MAX;
                }
            }
        }
        
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            Pos p = q.front();
            q.pop();
            
            for (auto dir : dirs) {
                int row = dir[0] + p.row, col = dir[1] + p.col;
                if (row < 0 || row >= R || col < 0 || col >= C) continue;
                // 位置 p 不能使该邻居的距离变小，不需要更新邻居的举例，
                // 所以邻居不需要传播它的影响，不需要入队。
                if (matrix[row][col] <= (matrix[p.row][p.col] + 1)) continue;
                matrix[row][col] = matrix[p.row][p.col] + 1;
                q.push(Pos(row, col));
            }
        }
        
        return matrix;
    }
};