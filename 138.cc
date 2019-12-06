/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
      if (!head) return NULL;
      
      unordered_map<Node*, Node*> map;
      Node *clone_head, *orignal_head, *new_head;
      clone_head = new Node(head->val, NULL, NULL);
      orignal_head = head;
      map[head] = clone_head;
      new_head = clone_head;
      while (orignal_head->next) {
        Node *n = new Node(orignal_head->next->val, NULL, NULL);
        new_head->next = n;
        map[orignal_head->next] = new_head->next;
        new_head = new_head->next;
        orignal_head = orignal_head->next;
      }
      new_head = clone_head;
      while (head) {
        if (head->random) {
          new_head->random = map[head->random];
        }
        head = head->next;
        new_head = new_head->next;
      }
      return clone_head;
    }
};