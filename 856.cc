class Solution {
public:
    int scoreOfParentheses(string S) {
        reverse(S.begin(), S.end());
        stack<int> stk;
        int res = 0;
        
        for (int i = 0; i < S.size(); ++i) {
            char c = S[i];
            
            if (c == ')') { // 从后往前算，遇到一个 ) 表示增加一倍
                if (stk.empty()) {
                    stk.push(1);
                } else {
                    stk.push(2 * stk.top());
                }
            } else {
                if (S[i-1] == ')') { // 表示遇到最内侧括号
                    res += stk.top();
                }
                stk.pop(); // 遇到一个 ( 减少一倍
            }
        }
        return res;
    }  
};


// 用指数替代栈.
class Solution {
public:
    int scoreOfParentheses(string S) {
        reverse(S.begin(), S.end());
        int res = 0;
        
        int expo = -1;
        for (int i = 0; i < S.size(); ++i) {
            char c = S[i];
            
            if (c == ')') {
                expo += 1;
            } else {
                if (S[i-1] == ')') { //最内侧括号
                    res += pow(2, expo);
                }
                expo -= 1;
            }
        }
        return res;
    }  
};