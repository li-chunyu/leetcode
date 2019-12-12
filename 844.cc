// time O(n)
// space O(1)
class Solution {
public:
    bool backspaceCompare(string S, string T) {
      int idx1 = S.size() - 1, idx2 = T.size() - 1;
      while (idx1 >= 0 || idx2 >= 0) {
        auto p1 = get_char(S, idx1);
        auto p2 = get_char(T, idx2);
        if (p1.first != p2.first)
          return false;
        idx1 = p1.second;
        idx2 = p2.second;
      }
      return true;
    }
    
    pair<char, int> get_char(string s, int idx) {
      char c = '\0';
      int  skip = 0;
      while (idx >= 0 && c == '\0') {
        if (s[idx] == '#') {
          skip++;
        } else if (skip != 0) {
          skip--;
        } else {
          c = s[idx];
        }
        idx--;
      }
      return make_pair(c, idx);
    }
};


// O(n) O(n)
class Solution {
public:
    bool backspaceCompare(string S, string T) {
      stack<char> s;
      stack<char> t;
      helper(s, S);
      helper(t, T);
      if (s.size() != t.size()) return false;
      while (!s.empty()) {
        if (s.top() != t.top()) return false;
        s.pop();
        t.pop();
      }
      return true;
    }
    
  void helper(stack<char> &st, string s) {
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '#') {
        if (!st.empty())
          st.pop();
        else
          continue;
      } else {
        st.push(s[i]);
      }
    }
  }
};