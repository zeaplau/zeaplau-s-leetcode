#
# @lc app=leetcode.cn id=107 lang=python3
#
# [107] 二叉树的层序遍历 II
#

# @lc code=start
# Definition for a binary tree node.
from typing import List, Optional
from collections import deque

class Solution:
    def levelOrderBottom(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None:
            return list()

        # 构建一个队列
        queue = deque([root])
        # 这个是最后的全部结果
        level_order = list()
        while queue:
            # 用于保留每一层的结果
            level = list()
            # 这一层有 size 个节点
            size = len(queue)
            for _ in range(size):
                # 将这些节点取出后，将值加入到每一层保留的结果中
                node = queue.popleft()
                level.append(node.val)
                # 如果他有左右子节点，就是说明下一层还有节点
                # 就把他们加到队列中
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            level_order.append(level)
        return level_order[::-1]

# @lc code=end

