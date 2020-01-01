// 1. 记录每一个字母最后一次出现的 index（记为index_last_seen).
// 2. 记录目前为止见到的最大的 index_last_seen, 如果right等于
//    index_last_seen，子串[left, right] 中的字母在[right+1, ] 中没有出现，
//    所以可以分割。
class Solution {
public:
    vector<int> partitionLabels(string S) {
      int last['z' - 'a' + 1] = {-1};
      for (int i = 0; i < S.size(); ++i) last[S[i] - 'a'] = i;
      
      vector<int> ret;
      for (int left = 0, right = 0, max_last = INT_MIN; right < S.size(); ++right) {
        max_last = max(max_last, last[S[right]-'a']);
        if (max_last == right) {
          ret.push_back(right-left+1);
          left = right + 1;
        }
      }
      return ret;
    }
};