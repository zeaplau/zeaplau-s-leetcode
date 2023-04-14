#
# @lc app=leetcode.cn id=113 lang=python3
#
# [113] 路径总和 II
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

'''
    记得加 `deepcopy`
'''

from typing import Optional, List
from copy import deepcopy

class Solution:
    def __init__(self) -> None:
        self.path = []
        self.ans = []

    def dfs(self, root: Optional[TreeNode], targetSum: int, path: List[int]):
        if root is None:
            return

        if root.left is None and root.right is None:
            # 对比是否添加路径
            # print("All None: ", self.path, "Value: ", root.val, "Target: ", targetSum)
            if targetSum == root.val:
                self.path.append(root.val)
                # print("== :", self.path)
                self.ans.append(deepcopy(self.path))
                # print("== :", self.ans)
                self.path.pop()
                return
            else:
                return
        
        # print("append after: ", self.path, "value: ", root.val)
        self.path.append(root.val)
        # print("append after: ", self.path, "value: ", root.val)
        self.dfs(root.left, targetSum - root.val, path=self.path)
        # print("middle: ", self.path, "value: ", root.val)
        self.dfs(root.right, targetSum - root.val, path=self.path)
        self.path.pop()
        # print("rootVal: ", root.val, "answer: ", self.ans)

    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        # 如果 root 为空
        if root is None:
            return  []
        
        # 如果只有 root 这么一个节点
        if root.left is None and root.right is None:
            if targetSum == root.val:
                return [[root.val]]

        self.path = [root.val]
        self.ans = []
        self.dfs(root.left, targetSum=targetSum - root.val, path=self.path)
        self.dfs(root.right, targetSum=targetSum - root.val, path=self.path)
        return self.ans

# @lc code=end

