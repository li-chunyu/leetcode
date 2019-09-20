class Solution {
public:
    bool isValid(string s) {
        stack<char> left;
        bool is_valid = true;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                left.push(s[i]);
            else {
                if (left.size() == 0) {
                    is_valid = false;
                    break;
                }
                char c = left.top();
                left.pop();
                if (c == '(') {
                    if (s[i] != ')') {
                        is_valid = false;
                        break;
                    }
                } else if (c == '[') {
                    if (s[i] != ']') {
                        is_valid = false;
                        break;
                    }
                } else {
                    if(s[i] != '}') {
                        is_valid = false;
                        break;
                    }
                }
                
            }
        }
        if (left.size() != 0)
            is_valid = false;
        return is_valid;
    }
};
