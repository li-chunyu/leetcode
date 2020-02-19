// Test case 有点问题.

#include <iostream>
using namespace std;

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList(): head_(NULL), length_(0) {
        
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
      if (index > length_ - 1) return -1;
      LinkNode *cur = head_;
      for (int i = 0; i < index; ++i)
        cur = cur->next;
      return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        LinkNode *tmp = head_;
        head_ = new LinkNode(val);
        head_->next = tmp;
        length_ += 1;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
      LinkNode **tail = &head_;
      while ((*tail) != NULL) tail = &(*tail)->next;
      *tail = new LinkNode(val);
      length_ += 1;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > length_ - 1) return;
        LinkNode **cur = &head_;
        for (int i = 0; i < index; ++i)
          cur = &(*cur)->next;
        LinkNode *tmp = *cur;
        *cur = new LinkNode(val);
        (*cur)->next = tmp;
        length_ += 1;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
      if (index > length_ - 1) return;
      LinkNode **cur = &head_;
      for (int i = 0; i < index; ++i)
        cur = &(*cur)->next;
      LinkNode *tmp = *cur;
      *cur = (*cur)->next;
      delete tmp;
      length_ -= 1;
    }

    void print() {
      LinkNode *cur = head_;
      while (cur) {
        cout << cur->val << ", ";
        cur = cur->next;
      }
      cout << endl;
    }

private:
  struct LinkNode {
    int val;
    LinkNode *next;
    LinkNode(int i): val(i), next(NULL) {}
  };

  LinkNode *head_;
  int length_;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main() {
  MyLinkedList linkedList;
  linkedList.addAtHead(1);
  linkedList.addAtTail(3);
  linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3

  linkedList.print();
  int i = 0;
  bool f = true;
  if ((i = linkedList.get(1)) != 2) {
    f = false;
  }           // returns 2
  linkedList.deleteAtIndex(1);  // now the linked list is 1->3
  if ((i = linkedList.get(1)) != 3) {
    f = false;
  }
  if (f)
    cout << "Success." << endl;
  else
    cout << "Fail" << endl;
  return 0;
}