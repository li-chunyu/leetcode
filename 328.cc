
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head)  return NULL;
        ListNode** odd;
        ListNode** even;
        odd = &head->next;
        even = &head->next;
        int ncur = 2;
        for (ListNode* cur = head->next; cur != NULL;) {
            ListNode* tmp;
            if (ncur % 2) {
                ListNode* tt;
                tmp = cur->next;
                tt = *odd;
                *odd = cur;
                cur->next = tt;
                odd = &(cur->next);
            } else {
                tmp = cur->next;
                cur->next = NULL;
                *even = cur;
                even = &(cur->next);
            }
            cur = tmp;
            ncur++;
        }
        return head;
    }
};