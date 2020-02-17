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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode* res = head;
        while (res->next != NULL) res = res->next;
        ListNode *tail = revList(head);
        tail->next = NULL;
        return res;
    }
    
    ListNode* revList(ListNode* head) {
        if (head->next == NULL) return head;
        ListNode* tail = revList(head->next);
        tail->next = head;
        return head;
    }
}; 

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
    ListNode* reverseList(ListNode* head) {
        ListNode* newhead = NULL;
        while (head != NULL) {
            ListNode* tmp = newhead;
            ListNode* tmp2 = head->next;
            newhead = head;
            head->next = tmp;
            head = tmp2;
        }
        return newhead;
    }
};