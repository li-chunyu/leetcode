class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return vector<string>();
        }
        const vector<string> key = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ret = {""};
        for (int i = 0; i < digits.size(); ++i) {
            string cands = key[digits[i] - '0'];
            vector<string> tmp;
            for (int j = 0; j < ret.size(); ++j)
                for (int jj = 0; jj < cands.size(); ++jj)
                    tmp.push_back(ret[j]+cands[jj]);
            ret.swap(tmp);
        }
        return ret;
    }
};