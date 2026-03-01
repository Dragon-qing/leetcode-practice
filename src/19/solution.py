'''
Author: Dragon-qing
Date: 2026-03-01
LastEditors: Dragon-qing
FilePath: \leetcode\src\19\solution.py
Description: 链表--删除倒数第n个元素
'''
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dummy = ListNode(0, head)
        prev, now = dummy, head
        for i in range(n):
            now = now.next
        while now:
            prev = prev.next
            now = now.next
        prev.next = prev.next.next
        return dummy.next