#
# @lc app=leetcode.cn id=129 lang=python3
#
# [129] 求根节点到叶节点数字之和
#

# @lc code=start
# Definition for a binary tree node.
from typing import Optional
from copy import deepcopy

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def __init__(self) -> None:
        self.collection = list()

    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        def dfs(root: Optional[TreeNode], cur_num: int):
            if root is None:
                return

            if root.left is None and root.right is None:
                num = cur_num * 10 + root.val
                self.collection.append(num)
                
                print("collection: {}".format(self.collection))
                return
            
            num = cur_num * 10 + root.val
            dfs(root=root.left, cur_num=num)
            dfs(root=root.right, cur_num=num)
        
        if root is None:
            return 0
        # 第一次做错是因为漏了这个情况
        if root.left is None and root.right is None:
            return root.val

        num = root.val
        dfs(root=root.left, cur_num=num)
        dfs(root=root.right, cur_num=num)
        return sum(self.collection)

# @lc code=end

