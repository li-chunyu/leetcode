class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
      k_ = k;
      for (auto i : nums) {
        min_q_.push(i);
      }
      while (min_q_.size() > k) {
        min_q_.pop();
      }
    }
    
    int add(int val) {
      if (min_q_.size() < k_) {
        min_q_.push(val);
        return min_q_.top();
      }
      if (val <= min_q_.top())
        return min_q_.top();
      else {
        min_q_.push(val);
        min_q_.pop();
        return min_q_.top();
      }
    }
  
private:
  priority_queue<int, vector<int>, greater<int>> min_q_;
  int k_;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */