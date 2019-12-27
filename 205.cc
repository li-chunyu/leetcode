// space O(n) MLE
class Solution {
public:
    bool isIsomorphic(string s, string t) {
      string p1 = strtopattern(s);
      string p2 = strtopattern(t);
      return p1 == p2? true: false;
    }
  
    string strtopattern(string s) {
      unordered_map<char, int> chartoid;
      int id = 0;
      string pattern = "";
      for (auto c : s) {
        if (chartoid.find(c) == chartoid.end()) {
          chartoid[c] = id;
          pattern = pattern + to_string(id);
          id++;
        } else {
          pattern = pattern + to_string(chartoid[c]);
        }
      }
      return pattern;
    }
};