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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int nA = 0, nB = 0;
        ListNode *tmpheadA = headA;
        ListNode *tmpheadB = headB;
        while (tmpheadA != NULL) {
            nA++;
            tmpheadA = tmpheadA->next;
        }
        while (tmpheadB != NULL) {
            nB++;
            tmpheadB = tmpheadB->next;
        }
        if (nA > nB) {
            for (int i = 0; i < nA-nB; ++i) {
                headA = headA->next;
            }
        } else if (nB > nA) {
            for (int i = 0; i < nB-nA; ++i) {
                headB = headB->next;
            }
        }
        
        while (headA!=NULL && headB!=NULL) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL; 
        
    }
};
