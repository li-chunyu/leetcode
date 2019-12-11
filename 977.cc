class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
      int neg = 0, pos = -1;
      while (++pos<A.size()&&A[pos] < 0);
      neg = pos - 1;
      vector<int> ret;
      while (neg >=0 && pos < A.size()) {
        if (abs(A[neg]) < abs(A[pos])) {
          ret.push_back(A[neg]*A[neg]);
          neg--;
        } else {
          ret.push_back(A[pos]*A[pos]);
          pos++;
        }
      }
      if (pos != A.size()){
        for (int i = pos; i < A.size();++i) {
          ret.push_back(A[i]*A[i]);
        }
      }
      if (neg != -1) {
        for (int i = neg; i >= 0; --i) {
          ret.push_back(A[i]*A[i]);
        }
      }
      return ret;
    }
};

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
      int pos = lower_bound(A.begin(), A.end(), 0) - A.begin();
      int neg = pos - 1;
      vector<int> ret;
      for (; pos < A.size() || neg >= 0;){
        if (abs(pos < A.size()?A[pos]:INT_MAX) <
            abs(neg >= 0?A[neg]:INT_MAX)) {
          ret.push_back(pow(A[pos++], 2));
        } else {
          ret.push_back(pow(A[neg--], 2));
        }
      }
      return ret;
    }
};