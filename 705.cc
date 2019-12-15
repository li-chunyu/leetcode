#include <iostream>
#include <vector>
#include <ctype.h>
using namespace std;

class MyHashSet {
public:
  struct Elem {
    int value;
    Elem *next;
    Elem(int v): value(v), next(NULL){}
  };

  /** Initialize your data structure here. */
  MyHashSet(): hash_size_(1000), bucket_list_tail_(0) {
    list_head_ = NULL;
    bucket_list_tail_ = static_cast<size_t>(-1);
    buckets_.resize(hash_size_, HashBucket(0, NULL));
  }
  
  void add(int key) {
    if (contains(key)) return;

    size_t index = (static_cast<size_t>(key) % hash_size_);
    HashBucket &bucket = buckets_[index];

    Elem *elem = new Elem(key);
    if (bucket.last_elem == NULL) { // unocuppied bucket
      if (bucket_list_tail_ == static_cast<size_t>(-1)) {
        list_head_ = elem;
      } else {
        buckets_[bucket_list_tail_].last_elem->next = elem;
      }
      elem->next = NULL;
      bucket.last_elem = elem;
      bucket.prev_bucket = bucket_list_tail_;
      bucket_list_tail_ = index;
    } else {
      elem->next = bucket.last_elem->next;
      bucket.last_elem->next = elem;
      bucket.last_elem = elem;
    }
  }
  
  void remove(int key) {
    if (!contains(key)) return;
    size_t index = (static_cast<size_t>(key) % hash_size_);
    HashBucket &bucket = buckets_[index];
    Elem *head = (bucket.prev_bucket == static_cast<size_t>(-1)?
                  list_head_:
                  buckets_[bucket.prev_bucket].last_elem->next);
    Elem *tail = bucket.last_elem;
    for (Elem *e = head; e != tail; e = e->next) {
      if (e->next->value == key) {
        Elem *elem = e->next;
        e->next = e->next->next;
        delete elem;
        break;
      }
    }
  }
  
  /** Returns true if this set contains the specified element */
  bool contains(int key) {
    size_t index = (static_cast<size_t>(key) % hash_size_);
    HashBucket &bucket = buckets_[index];
    if (bucket.last_elem != NULL) {
      Elem *head = (bucket.prev_bucket == static_cast<size_t>(-1)?
                    list_head_->next:
                    buckets_[bucket.prev_bucket].last_elem->next);
      Elem *tail = bucket.last_elem->next;
      for (Elem *e = head; e != tail; e = e->next)
        if (e->value == key) return true;
      return false;
    } else {
      return false;
    }
  }

private:

  struct HashBucket {
    size_t prev_bucket;
    Elem *last_elem;
    HashBucket(size_t i, Elem *e): prev_bucket(i), last_elem(e){}
  };
  Elem *list_head_; // head of current list head.

  size_t hash_size_; // number of hash bukets.
  size_t bucket_list_tail_; // last active bucket.
  vector<HashBucket> buckets_;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

int main() {
  // test case
  MyHashSet *obj = new MyHashSet();
  //cout << "contains " << 6000 << " " << obj->contains(6000) << endl;
 // obj->add(6000);
  obj->add(6000);
  cout << "contains " << 6000 << " " << obj->contains(6000) << endl;
  obj->remove(6000);
  obj->remove(6000);
  cout << "contains " << 6000 << " " << obj->contains(6000) << endl;
  return 0;
}