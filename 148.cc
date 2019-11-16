/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
      ListNode* b_head = head;
      int N = 0;
      while (b_head != NULL) {
        N++;
        b_head = b_head->next;
      }
      ListNode *gard = new ListNode(-1);
      gard->next = head;
      ListNode *lo, *hi;
      for (int sz = 1; sz < N; sz = sz + sz) {
        ListNode *cur = gard->next;
        ListNode *tail = gard;
        while (cur != NULL) {
          lo = cur;
          hi = split(lo, sz);
          cur = split(hi, sz);
          tail = merge(lo, hi, tail);
        }
      }
      return gard->next;
    }
    
    ListNode* merge(ListNode *lo, ListNode *hi, ListNode *head) {
      while (lo && hi) {
        if (lo->val > hi->val) {
          head->next = hi;
          hi = hi->next;
        } else {
          head->next = lo;
          lo = lo->next;
        }
        head = head->next;
      }
      if (lo != NULL) {
        head->next = lo;
      } else {
        head->next = hi;
      }
      while (head->next != NULL) head = head->next;
      return head;
    }
  
    ListNode* split(ListNode* head, int sz) {
      for (int i = 0; head && i < sz-1; ++i){
        head = head->next;
      }
      if (head == NULL) return NULL;
      ListNode* ret = head->next;
      head->next = NULL;
      return ret;
    }
};