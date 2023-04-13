#
# @lc app=leetcode.cn id=110 lang=python3
#
# [110] 平衡二叉树
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
'''
    分治，这里用的是暴力
'''
from typing import Optional

class Solution:
    # 获取最深的节点
    # 以 root 为根，获取最深的高度
    def dfs(self, root):
        # 如果遇到了空节点，说明已经到了底部
        if root is None:
            return 0
        # 不断加深层数
        return max(self.dfs(root.left), self.dfs(root.right)) + 1
    
    # 带有剪枝的方法
    def recur(self, root):
        # 遇到了空节点，说明到了底部
        if root is None:
            return 0
        # 分别进去左右节点
        left = self.recur(root.left)
        if left == -1:
            return -1
        right = self.recur(root.right)
        if right == -1:
            return -1
        # 重点是这句
        # 取左右最大的那个
        return max(left, right) + 1 if abs(left - right) < 2 else -1


    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        # 特例判断，如果树根是空的，直接返回它是平衡树
        if root is None:
            return True
        # 题目的三个条件
        # 不超过 1，左右节点是平衡树
        return abs(self.dfs(root.left) - self.dfs(root.right)) <= 1 and self.isBalanced(root.left) and self.isBalanced(root.right)
# @lc code=end

