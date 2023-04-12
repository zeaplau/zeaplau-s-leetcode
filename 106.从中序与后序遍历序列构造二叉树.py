#
# @lc app=leetcode.cn id=106 lang=python3
#
# [106] 从中序与后序遍历序列构造二叉树
#

# @lc code=start
# Definition for a binary tree node.
from typing import List, Optional

# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

'''
    Same as Title. 105
    ※ Remember
        - in_left, in_right mean the index of left / right subtree sub-range in the original inorder list.
        - pos_left, pos_right mean the index of left / right subtree sub-range in the original postorder list.
'''

class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        def recursive(inorder: List[int], postorder: List[int], in_left: int, in_right: int, pos_left: int, pos_right: int):
            '''
                Build the subtree recursively.

                :param inorder: The inorder list.
                :param postorder: The postorder list.
                :param in_left: The left index in the inorder list for the corresponding subtrees.
                :param in_right: The right index in the inorder list for the corresponding subtrees.
                :param pos_left: The left index in the postorder list for the corresponding subtrees.
                :param pos_right: The right index in the postorder list for the corresponding subtrees.
            '''
            if in_left > in_right:
                return None

            # Get root val
            root_val: int = postorder[pos_right]
            # Get root index
            root_idx = index[root_val]

            left_subtree_size = root_idx - in_left

            # Create root node
            root = TreeNode(root_val)
            # Create left subtree
            root.left = recursive(inorder, postorder, in_left, root_idx - 1, pos_left, pos_left + left_subtree_size - 1)
            # Create right subtree
            root.right = recursive(inorder, postorder, root_idx + 1, in_right, pos_left + left_subtree_size, pos_right - 1)
            return root

        index = {ele: idx for idx, ele in enumerate(inorder)}
        res = recursive(inorder, postorder, 0, len(inorder) - 1, 0, len(postorder) - 1)
        return res


# @lc code=end

