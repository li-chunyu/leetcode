class Solution {
public:

    int next(int n) {
      vector<int> ret;
      while (n != 0) {
        ret.push_back(n%10);
        n /= 10;
      }
      int nxt = 0;
      for (auto d : ret) {
        nxt += pow(d, 2);
      }
      return nxt;
    }
  
    bool isHappy(int n) {
      int slow = n, fast = n;
      fast = next(next(fast));
      while (fast != slow) {
        slow = next(slow);
        fast = next(next(fast));
      }
      return fast == 1?true:false;
    }

};