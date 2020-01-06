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
    ListNode* swapPairs(ListNode* head) {
        ListNode **cur, *first;
        cur = &head;
        while (*cur && (*cur)->next) {
            first = *cur;
            *cur = (*cur)->next;
            first->next = (*cur)->next;
            (*cur)->next = first;
            cur = &((*cur)->next->next);
        }
        return head;
    }
};