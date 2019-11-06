class Solution {
public:
    int numSquares(int n) {
      if (n == 0)
        return 0;
      if (n == 1)
        return 1;
      vector<int> T(n+1, 0);
      vector<int> subs;
      int j = floor(sqrt(n));
      for (int i = 1; i <= j; ++i) {
        subs.push_back(i*i);
      }
      T[0] = 0; T[1] = 1;
      for (int i = 2; i < T.size(); ++i) {
        int m = INT_MAX;
        for (auto sub : subs) {
          if (i - sub >= 0)
            m = min(m, T[i-sub]+1);
        T[i] = m;
        }
      }
      return T[n];
    }
};