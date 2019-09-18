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
    bool hasCycle(ListNode *head) {
        ListNode *one_step = head;
        ListNode *two_step = head;
        while (two_step != NULL && two_step->next != NULL) {
            one_step = one_step->next;
            two_step = two_step->next->next;
            if (one_step == two_step) {
                return true;
            }
        }
        return false;
        
    }
};
