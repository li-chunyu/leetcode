class Solution {
public:
    string decodeString(string s) {
      string res = "";
      stack<int> num_stack;
      stack<string> str_stack;
      int num = 0;
      for (char c : s) {
        if (isdigit(c)) {
          num = num*10 + (c - '0');
        } else if (isalpha(c)) {
          res.push_back(c);
        } else if (c == '[') {
          str_stack.push(res);
          num_stack.push(num);
          num = 0;
          res = "";
        } else if (c == ']') {
          string tmp = res;
          int n = num_stack.top();
          num_stack.pop();
          for (int i = 0; i < n-1; ++i) {
            tmp += res;
          }
          res = str_stack.top() + tmp;
          str_stack.pop();
        }
      }
      return res;
    }
};