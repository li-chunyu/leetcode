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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      int left = 0, right = 0;
      ListNode *dumy = new ListNode(-1);
      ListNode *pleft = dumy, *pright = dumy;
      dumy->next = head;
      while (right - left != n) {
        right++;
        pright = pright->next;
      }
      while (pright->next != NULL) {
        pright = pright->next;
        pleft = pleft->next;
      }
      pleft->next = pleft->next->next;
      return dumy->next;
    }
};