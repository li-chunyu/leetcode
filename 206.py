# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head == None or head.next == None:
            return head
        l = head
        r = head.next
        while r != None:
            tmp = r.next
            r.next = l
            l = r
            r = tmp
        head.next = None
        return l