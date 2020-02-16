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


//  rec version
class Solution {
public:
    string decodeString(string s) {
        int idx = 0;
        return decodeStr(s, idx);
    }
    
    string decodeStr(string& s, int& idx) {
        int times = 1;
        string res = "";
        
        for (; idx < s.size(); ++idx) {
            char c = s[idx];
            if (isdigit(c)) {
                string t = "";
                while (isdigit(s[idx]))
                    t += s[idx++];
                idx--;
                times = stoi(t);
            } else if (c >= 'a' && c <= 'z'){
                //for (int j = 0; j < times; ++j) res += c;
                res += c;
            } else if ( c == '[') {
                idx += 1;
                string str = decodeStr(s , idx);
                for (int j = 0; j < times; ++j) res += str;
                times = 1;
            } else if (c == ']') {
                return res;
            } else if (c >= 'A' && c <= 'Z') {
                res += c;
            }
        }
        return res;
    }
};