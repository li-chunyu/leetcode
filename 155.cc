class MinStack {
private:
    forward_list<int> linked_list;
    int min;
    int cnt;
public:
    /** initialize your data structure here. */
    MinStack() {
        linked_list = forward_list<int>();
        min = INT_MAX;
        cnt = 0;
    }
    
    void push(int x) {
        linked_list.push_front(x);
        if (x < min) {
            min = x;
        }
        cnt++;
    }
    
    void pop() {
        int t = top();
        linked_list.pop_front();
        if (t == min) {
            min = INT_MAX;
            for (auto ele: linked_list) {
                if (ele < min) {
                    min = ele;
                }
            } 
        }
    }
    
    int top() {
        return linked_list.front();
    }
    
    int getMin() {
        return min; 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */