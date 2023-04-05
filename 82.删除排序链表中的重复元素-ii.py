#
# @lc app=leetcode.cn id=82 lang=python3
#
# [82] 删除排序链表中的重复元素 II
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
        # 这里的一个技巧是，弄一个哑节点，然后复制这个哑节点
        # 用这个复制后的节点进行操作，这样就能保留哑节点
        if head is None:
            return head

        dummy = ListNode(0, head)
        cur = dummy

        while cur.next and cur.next.next:
            if cur.next.val == cur.next.next.val:
                val = cur.next.val
                # 如果中间的这个节点不是空的，并且这个中间节点和重复的值相同
                while cur.next and cur.next.val == val:
                    # 跳过中间的一个节点
                    # 这里有保留着 cur.next 的意思，这样能够一直用这个值来进行比较
                    cur.next = cur.next.next
            else:
                # 两个前后的节点数值不同，那就往后走
                cur = cur.next

        return dummy.next

# @lc code=end

