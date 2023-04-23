#
# @lc app=leetcode.cn id=160 lang=python3
#
# [160] 相交链表
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
'''
    A 先走完 A 链表，B 再走完 B 链表
    a + (b - c) = b + (a - c)
    如果有公共节点，那么随机返回一个即可
    如果没有，返回 None 也可以，所以返回 A 就好了
'''
from typing import Optional

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        A, B = headA, headB
        while A != B:
            A = A.next if A else headB
            B = B.next if B else headA
        return A

# @lc code=end

