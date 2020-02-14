class Solution {
public:
    string countOfAtoms(string formula) {
        reverse(formula.begin(), formula.end());
        map<string, int> cnt;
        count(formula, cnt);
        string res = "";
        
        for (auto iter = cnt.begin(); iter != cnt.end(); iter++) {
            if ((*iter).second != 1)
                res += (*iter).first + to_string((*iter).second);
            else
                res += (*iter).first;
        }
        
        return res;
    }
    
    void count(string& formula, map<string, int>& cnt) {
        stack<int> stk;
        int factor = 1;
        string elem = "";
        
        stk.push(1);
        for (int i = 0; i < formula.size(); ++i) {
            char c = formula[i];
            if (isdigit(c)) {
                string s = "";
                while (isdigit(formula[i]))
                    s += formula[i++];
                reverse(s.begin(), s.end());
                factor = stoi(s);
                i--; // for loop will add i by 1.
            } else if (c == ')'){
                stk.push(factor * stk.top());
                factor = 1;
            } else if (c >= 'A' && c <= 'Z') {
                elem = c;
                if (cnt.find(elem) == cnt.end())
                    cnt[elem] = factor * stk.top();
                else
                    cnt[elem] += factor * stk.top();
                factor = 1;
                elem = "";
            } else if (c >= 'a' && c <= 'z') {
                while (formula[i] >= 'a' && formula[i] <= 'z')
                    elem += formula[i++];
                elem += formula[i]; // formula[i] must be A ... Z.
                reverse(elem.begin(), elem.end());
                if (cnt.find(elem) == cnt.end())
                    cnt[elem] = factor * stk.top();
                else
                    cnt[elem] += factor * stk.top();
                factor = 1;
                elem = "";
            } else if (c == '(') {
                stk.pop();
            }
        }
    }
};