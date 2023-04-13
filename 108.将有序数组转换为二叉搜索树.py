#
# @lc app=leetcode.cn id=108 lang=python3
#
# [108] 将有序数组转换为二叉搜索树
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

'''
    没啥意思的题目，就是不断地取中点作为根节点，
    其实有一个有意思的知识点就是，二叉搜索树其实
    就是有序数组
'''
from typing import Optional, List

class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        def recursive(left, right):
            if left > right:
                return None
            mid = (left + right) // 2
            root = TreeNode(nums[mid])
            root.left = recursive(left, mid - 1)
            root.right = recursive(mid + 1, right)
            return root

        return recursive(0, len(nums) - 1)

# @lc code=end


