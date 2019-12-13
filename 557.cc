class Solution {
public:
    string reverseWords(string s) {
      string::iterator left_it, right_it;
      left_it = s.begin();
      right_it = left_it;
      while (right_it != s.end()) {
        while (left_it != s.end() && *left_it == ' ') left_it++;
        right_it = left_it;
        right_it++;
        while (right_it != s.end() && *right_it != ' ') right_it++;
        reverse(left_it, right_it);
        left_it = right_it;
      }
      return s;
    }
};