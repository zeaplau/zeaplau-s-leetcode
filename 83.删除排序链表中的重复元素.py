#
# @lc app=leetcode.cn id=83 lang=python3
#
# [83] 删除排序链表中的重复元素
#

# @lc code=start
# Definition for singly-linked list.
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return head

        dummy = ListNode(0, head)
        cur = dummy

        # cur.next -> slow
        # cur.next.next -> fast
        while cur.next.next:
            # 如果快一步的指针和现在这个慢指针值相同
            if cur.next.val == cur.next.next.val:
                # 那就跳过这个快指针，指向快指针的下一个节点
                cur.next.next = cur.next.next.next
            else:
                # 如果不同，那就正常移动
                cur = cur.next

        return dummy.next


# @lc code=end

