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