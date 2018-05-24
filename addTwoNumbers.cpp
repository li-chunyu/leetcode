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
        ListNode* head = NULL;
        ListNode* pn = NULL;
        int digit = 0;
        int carry = 0;

        while (l1 || l2 || carry) {
            if (head == NULL){
                head = new ListNode(0);
                pn = head;
            } else {
                pn->next = new ListNode(0);
                pn = pn->next;
            }
            digit = getVal(l1) + getVal(l2) + carry;
            carry = digit / 10;
            pn->val = digit % 10;

            l1=l1?l1->next:NULL;
            l2=l2?l2->next:NULL;
        }
        return head;
    }

    int getVal(ListNode* l){
        if (l != NULL)
            return l->val;
        if (l == NULL)
            return 0;
    }
};