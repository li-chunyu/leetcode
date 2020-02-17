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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res_head = new ListNode(-1);
        ListNode* cur = res_head;
        int grad = 0;
        while (l1 != NULL || l2 != NULL || grad != 0) {
            int op1 = l1 != NULL?l1->val:0;
            int op2 = l2 != NULL?l2->val:0;
            int d = op1 + op2 + grad;
            grad = d / 10;
            cur->next = new ListNode(d % 10);
            cur = cur->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return res_head->next;
    }
};