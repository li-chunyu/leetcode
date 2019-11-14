class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
      if (s.size() == 0 || s.size() < p.size())
        return vector<int>();
      vector<int> ret;
      int ch[26] = {0};
      for (auto c : p) {
        ch[c-'a']++;
      }
      
      int left = 0, right = 0;
      int diff = p.size();
      for (right = 0; right < p.size(); ++right) {
        char tmp = s[right];
        ch[tmp-'a']--;
        if (ch[tmp-'a'] >= 0)
          diff--;
      }
      if (diff == 0)
        ret.push_back(0);
      while (right != s.size()) {
        char tmp = s[left];
        if (ch[tmp-'a'] >= 0) {
          diff++;
        }
        ch[tmp-'a']++;
        left++;
        tmp = s[right];
        ch[tmp-'a']--;
        if (ch[tmp-'a'] >= 0)
          diff--;
        if (diff == 0) {
          ret.push_back(left);
        }
        right++;
      }
      return ret;
    }
};