class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int pop = 0, push = 0;
        while (push != pushed.size()) {
            st.push(pushed[push]);
            push += 1;
            while (!st.empty() && popped[pop] == st.top()) {
                st.pop();
                pop += 1;
            }
        }
        return st.empty() ? true : false;
    }
};