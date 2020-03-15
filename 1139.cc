#include <iostream>
#include <vector>
#include "utils.h"
using namespace std;

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int a1 = grid.size(), a0 = grid[0].size();
        vector<vector<int>> axis0(a1, vector<int>(a0, 0));
        vector<vector<int>> axis1(a1, vector<int>(a0, 0));
        for (int i = 0; i < a1; ++i) {
            for (int j = 0; j < a0; ++j) {
                if (grid[i][j] == 1) {
                    j == 0? axis0[i][j] = 1: axis0[i][j] = axis0[i][j-1] + 1;
                    i == 0? axis1[i][j] = 1: axis1[i][j] = axis1[i-1][j] + 1;
                }
            }
        }

        PrintVector2D(axis0);
        cout << endl;
        PrintVector2D(axis1);
        int res = 0;
        for (int i = 0; i < a1; ++i) {
            for (int j = 0; j < a0; ++j) {
                if (grid[i][j] != 1) continue;
                int maxlen = min(axis0[i][j], axis1[i][j]);
                int len = 1;
                while (len <= maxlen) {
                    int cur = min(axis1[i][j-len+1], axis0[i-len+1][j]);
                    if (cur >= len)
                        res = max(len, res);
                    len++;
                }
            }
        }
        cout << res << endl;
        return res * res;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> v = {{1,1,1},{1,0,1},{1,1,1}};
    sol.largest1BorderedSquare(v);
}