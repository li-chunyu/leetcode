/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// priority_queue push 复杂度 O(logn), 
// 复杂度 O(nlogk) , k = lists.size(), n = 元素个数.
class Solution {
public:
    typedef pair<int, ListNode*> Elem;
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = NULL;
        ListNode** cur;
        cur = &head;
        auto cmp = [](Elem left, Elem right){return (left.second)->val > (right.second)->val;};
        priority_queue<Elem, vector<Elem>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < lists.size(); ++i)
            if (lists[i] != NULL)
                pq.push(make_pair(i, lists[i]));
        
        while (!pq.empty()) {
            Elem e= pq.top();
            pq.pop();
            *cur = e.second;
            if ((*cur)->next != NULL)
                pq.push(make_pair(e.first, (*cur)->next));
            (*cur)->next = NULL;
            cur = &(*cur)->next;
        }
        return head;
    }
};