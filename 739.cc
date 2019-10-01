///    使用单调栈来解， 单调递减栈(从栈顶到栈底)，当要压入一个元素时，
/// 所有要弹出的元素（还未找到比他们气温高的元素）均比当前要压入的元素
/// 气温低，所以这些要弹出的元素找到了最近的比他们气温高的元素，需要更新
/// ret数组
///  
/// 算法的最好最坏复杂度均为 O(n)， 因为 while 循环一共会执行 n 次，
/// 采用均摊分析， 将 while 均摊到 n 次for 循环上，最终复杂度为 O(n)，
/// **单调栈** 可以用来找最近的比当前元素大或者小的元素。
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ret(T.size(), 0);
        stack<pair<int, int> > monotone_stack;
        monotone_stack.push(make_pair(INT_MAX, -1));
        for (int i = 0; i < T.size(); ++i) {
            while (monotone_stack.top().first < T[i]) {
                auto p = monotone_stack.top();
                monotone_stack.pop();
                ret[p.second] = i - p.second;
            }
            monotone_stack.push(make_pair(T[i], i));
        }
        return ret;
    }
};