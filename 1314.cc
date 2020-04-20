class Solution {
public:
    struct Range {
        int r1;
        int r2;
        int c1;
        int c2;
        Range(int rr1, int rr2, int cc1, int cc2): r1(rr1), r2(rr2), c1(cc1), c2(cc2) {}
    };
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int H = mat.size();
        int W = mat[0].size();
        vector<vector<int>> pref(H, vector<int>(W));
        for (int r = 0; r < H; ++r) {
            for (int c = 0; c < W; ++c) {
                int x = (c == 0? 0 : pref[r][c-1]);
                int y = (r == 0? 0 : pref[r-1][c]);
                int z = ((c == 0 || r == 0)? 0 : pref[r-1][c-1]);
                // pref[r][c] = pref[r][c-1] + pref[r-1][c] - perf[r-1][c-1] + mat[r][c];
                pref[r][c] = x + y - z + mat[r][c];
            }
        }
        vector<vector<int>> ans(H, vector<int>(W));
        auto range = [&](int row, int col) -> Range {
            int r1, r2, c1, c2;
            r1 = row - K >= 0 ? row - K : 0;
            r2 = row + K < H ? row + K : H - 1;
            c1 = col - K >= 0 ? col - K : 0;
            c2 = col + K < W ? col + K : W - 1;
            return Range(r1, r2, c1, c2);
        };
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                Range ran = range(i, j);
                ans[i][j] = pref[ran.r2][ran.c2] - (ran.c1 - 1 >= 0?pref[ran.r2][ran.c1-1] : 0)
                                - (ran.r1-1 >= 0? pref[ran.r1-1][ran.c2] : 0)
                                + (ran.r1-1 >= 0 && ran.c1-1 >=0 ? pref[ran.r1-1][ran.c1-1] : 0);
            }
        }
        return ans;
        
    }
};
