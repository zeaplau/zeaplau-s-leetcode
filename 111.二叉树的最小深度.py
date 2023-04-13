#
# @lc app=leetcode.cn id=111 lang=python3
#
# [111] 二叉树的最小深度
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
'''
    这里出现了个错误
    只有左 / 右子树不为空的时候，才要进去进行判断
'''

from typing import Optional

class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        if root.left is None and root.right is None:
            return 1
        
        ans = 10**9
        # 进入左子树
        if root.left is not None:
            ans = min(self.minDepth(root.left), ans)
        # 进入右子树
        if root.right is not None:
            ans = min(self.minDepth(root.right), ans)
        # 最后加上根节点
        return ans + 1
# @lc code=end

