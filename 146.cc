class LRUCache {
public:
    LRUCache(int capacity):
      capacity_(capacity), n_(0){
    }
    
    int get(int key) {
      //unordered_map<int, list<int>::iterator>:: iter = kiter_.find(key);
      if (kv_.find(key) == kv_.end()) {
        return -1;
      }
      update(key);
      return kv_[key];
    }
    
    void put(int key, int value) {
      if (kv_.find(key) != kv_.end()) {
        kv_[key] = value;
        update(key);
        return;
      }
      if (n_ < capacity_) {
        kv_[key] = value;
        update(key);
        n_++;
      } else {
        int last_key = lru_.back();
        lru_.pop_back();
        kv_.erase(last_key);
        kiter_.erase(last_key);
        kv_[key] = value;
        update(key);
       }
      return;
    }
private:
  void update(int key) {
    if (kiter_.find(key) != kiter_.end())
      lru_.erase(kiter_[key]);
    lru_.push_front(key);
    kiter_[key] = lru_.begin();
  }
  
  unordered_map<int, int> kv_; // key-value
  unordered_map<int, list<int>::iterator> kiter_; // key-iterator_in_lru
  list<int> lru_; // lru
  int n_;
  int capacity_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */