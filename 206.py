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

# Recursion version 
class Solution:
    def RecReverseList(self, head: ListNode) -> ListNode:
        if head == None or head.next == None:
            return head
        h, t = self.reverse(head)
        t.next = None
        return h
         
    def reverse(self, head):
        if head.next == None:
            return head, head #(head, tail)
        h, t = self.reverse(head.next)
        t.next = head
        return h, head