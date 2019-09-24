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
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next!=NULL && fast->next->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *rev_head = reverse_list(slow->next);
        bool ret = true;
        while (rev_head!=NULL && head!=slow->next) {
            if (rev_head->val != head->val) {
                ret = false;
                break;
            }
            rev_head = rev_head->next;
            head = head->next;
        }
        return ret;
    }
    
    ListNode* reverse_list(ListNode *head) {
        ListNode* pre = NULL;
        ListNode* next = NULL;
        while (head != NULL) {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};
