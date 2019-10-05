/// 回溯(Backtrack) 类问题
/// 需要明确的 3 个问题：
///    1. Choice, 在每个状态下你有几个选择。
///    2. constrains, 对于你做出的选择有哪些限制。
///    3. 你的  目标是什么。
///
/// 对于这个题，以上是哪个问题是:
///    1. choice: 在每个状态下我们有 2 个选择，加一个"("或者")"
///    2. constrains: 每个状态下，对于加左括号的限制是必须还有左括号可用，
///       对于加右括号的限制是必须还有右括号可用并且还存在 open 的左括号(即有左括号可以和要加入的右括号匹配).
///       ("()"是 close, “()(”是 open=1)
///    3. goal: 目标是所有的左右括号都被用了。


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        extendParenthesis(ret, "", n, n, 0);        
        return ret;
    }
    
    void extendParenthesis(vector<string> &ret, string s, int left, int right, int open) {
        if (left ==0 && right == 0)
            ret.push_back(s);
        if (left > 0)
            extendParenthesis(ret, s+"(", left-1, right, open+1);
        if (open > 0 && right > 0)
            extendParenthesis(ret, s+")", left, right-1, open-1);
    }
};