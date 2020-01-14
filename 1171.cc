class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
      ListNode *root = new ListNode(0);
      root->next = head;
      unrodered_map<int, ListNode*> map;
      map[0] = root;
      int count = 0;
      while (head != NULL) {
        count += head->val;
        if (map.find(count) != map.end()) {
          ListNode *prev = map[count];
          ListNode *start = prev->next;
          prev->next = head->next;
          head->next = NULL;
          
          int ac = count;
          while (start != NULL) {
            ac += start->val;
            if (ac != 0)
              map.erase(ac);
            start = start->nxt;
          }
        } else {
          map[count] = head;
        }
        head = head->next;
      }
      return root->next;
    }
};