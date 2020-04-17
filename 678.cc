class Solution {
public:
   bool checkValidString(string s) {
        return helper(s, 0, 0);
    }
    bool helper(string& s, int index, int nleft) {
        if (index == s.size()) {
            return nleft == 0;
        }
        char c = s[index];
        if (c == '(') {
            nleft++;
            return helper(s, index+1, nleft);
        } else if (c ==')') {
            if (nleft == 0) {
                return false;
            } else {
                nleft--;
                return helper(s, index+1, nleft);
            }
        } else {
            s[index] = '(';
            bool a = helper(s, index, nleft);
            s[index] = ')';
            bool b = helper(s, index, nleft);
            bool c = helper(s, index+1, nleft);
            return a || b || c;
        }
    }
};
