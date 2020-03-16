class CustomStack {
public:
    CustomStack(int maxSize):nextPush(0), cap(maxSize) {
        container = vector<int>(cap, 0);
    }
    
    void push(int x) {
        if (nextPush == cap)
            return;
        else {
            container[nextPush] = x;
            nextPush++;
        }
    }
    
    int pop() {
        if (nextPush == 0) {
            return -1;
        } else {
            nextPush--;
            return container[nextPush];
        }
    }
    
    void increment(int k, int val) {
        int n = min(k, nextPush);
        for (int i = 0; i < n; ++i) {
            container[i] += val;
        }
        
    }
private:
    int nextPush;
    int cap;
    vector<int> container;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */