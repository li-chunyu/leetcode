class Solution {
public:
    bool isAnagram(string s, string t) {
      if (s.size() != t.size()) return false;
      if (s.size() == 0) return true;
      char map['z'-'a'+1] = {0};
      for (char c : s)
        map[c-'a'] += 1;
      for (char c : t)
        map[c-'a'] -= 1;
      for (int i = 0; i < ('z'-'a'+1); ++i)
        if (map[i] != 0)
          return false;
      
      return true;
    }
};
