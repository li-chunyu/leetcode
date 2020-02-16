// merge sort 中的 merge 操作

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res;
        int first_positive_idx = 0;
        while (first_positive_idx < A.size() &&
               A[first_positive_idx] < 0 &&
               ++first_positive_idx); // first positive number.
        int last_negtive_idx = first_positive_idx - 1;
        for (int i = 0; i < A.size(); ++i) {
            if (last_negtive_idx < 0) {
                res.push_back(A[first_positive_idx] * A[first_positive_idx]);
                first_positive_idx++;
            } else if (first_positive_idx > (A.size() - 1)) {
                res.push_back(A[last_negtive_idx] * A[last_negtive_idx]);
                last_negtive_idx--;
            } else if (abs(A[first_positive_idx]) > abs(A[last_negtive_idx])) {
                res.push_back(A[last_negtive_idx] * A[last_negtive_idx]);
                last_negtive_idx--;
            } else {
                res.push_back(A[first_positive_idx] * A[first_positive_idx]);
                first_positive_idx++;
            }
        }
        return res;
    }
};



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