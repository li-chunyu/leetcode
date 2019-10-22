class Solution {
public:
    int numTrees(int n) {
        vector<int> g(n+1, 0);
        g[0] = 1;
        g[1] = 1;
        for (int i = 2; i < g.size(); ++i) {
            for (int k = 0; k < i; ++k) {
                g[i] += g[k] * g[i-1-k];
            }
        }
        return g[n];
    }
};