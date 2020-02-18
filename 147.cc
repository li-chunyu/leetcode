class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL) return head;
        
        ListNode *sorted_head = head, *to_sort = head->next;
        sorted_head->next = NULL;
        while (to_sort != NULL) {
            ListNode** cur = &sorted_head;
            while ((*cur) != NULL && to_sort->val > (*cur)->val) cur = &(*cur)->next;
            ListNode *next = to_sort->next;
            ListNode *tmp = *cur;
            *cur = to_sort;
            to_sort->next = tmp;
            to_sort = next;
        }
        return sorted_head;
    }
};