// 过筛法
class Solution {
public:
    int countPrimes(int n) {
      if (n <= 2) return 0;
      int np = 1;
      int upper = int(sqrt(n));
      vector<bool> is_prime(n+1, true);
      for (int i = 3; i < n; i+=2) {
        if (is_prime[i]) {
          np++;
          // i*i 可能超出 int 的最大数值，故设置一个
          if (i > upper) continue;
          for (int j = i*i; j < n; j += i)
            is_prime[j] = false;
        }
      }
      return np;
    }
};