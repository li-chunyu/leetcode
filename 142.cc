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
    ListNode *detectCycle(ListNode *head) {
      ListNode *fast = head, *slow = head;
      while (fast && fast->next &&
             (slow = slow->next) &&
             (fast = fast->next->next) &&
             fast != slow);
      if (!fast || !(fast->next)) {
        return NULL;
      }
      slow = head;
      while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
      }
      return slow;
    }
};