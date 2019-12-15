class Solution {
public:
    int romanToInt(string s) {
      if (s.size() == 0) return 0;
      unordered_map<char, int> map = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
      };
      vector<int> add, sub;
      int ret = 0;
      for (int i = 0; i < s.size()-1; ++i){
        if (map[s[i]] < map[s[i+1]])
          ret -= map[s[i]];
        else
          ret += map[s[i]];
      }
      ret += map[s[s.size()-1]];
      return ret;
    }
};
