#
# @lc app=leetcode.cn id=105 lang=python3
#
# [105] 从前序与中序遍历序列构造二叉树
#

# @lc code=start
# Definition for a binary tree node.
from typing import List, Optional

# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# [[root], [p_left, ..., p_right], [i_left, ..., i_right]]，前序这样的
# [[p_left, ..., p_right], [root], [i_left, ..., i_right]]，中序是这样的
# 关键点是拿到 [p_left:p_right] 的长度，这样就能够确定传入的范围

class Solution:
    def __init__(self) -> None:
        self.index = {} # 存储中序的位置信息

    def recursive_build(self, preorder: List[int], inorder: List[int], preorder_left: int, preorder_right: int, inorder_left: int, inorder_right: int):
        # 结束条件
        if preorder_left > preorder_right:
            return None
        
        preorder_root_idx = preorder_left # 前序的根节点肯定在最前边
        inorder_root_idx = self.index[preorder[preorder_root_idx]] # 取根节点的值，然后获取它在中序的位置

        print(f"p_left: {preorder_left} p_right: {preorder_right} i_left: {inorder_left} i_right: {inorder_right} root_idx: {inorder_root_idx}")
        root = TreeNode(inorder[inorder_root_idx]) # 构建根节点
        left_subtree_size = inorder_root_idx - inorder_left
        # 注意无论是构建 左右子树，其传进去的范围是当前的前中遍历序列的范围
        # 构建左子树
        root.left = self.recursive_build(preorder=preorder, 
                                         inorder=inorder, 
                                         preorder_left=preorder_left + 1, 
                                         preorder_right=preorder_left + left_subtree_size, inorder_left=inorder_left, 
                                         inorder_right=inorder_root_idx - 1)
        # 构建右子树
        root.right = self.recursive_build(preorder=preorder, 
                                          inorder=inorder, 
                                          preorder_left=preorder_left + left_subtree_size + 1, 
                                          preorder_right=preorder_right, 
                                          inorder_left=inorder_root_idx + 1, 
                                          inorder_right=inorder_right)

        return root


    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        n = len(inorder)
        self.index = {val: i for i, val in enumerate(inorder)}
        res = self.recursive_build(preorder=preorder, inorder=inorder, 
                                    preorder_left=0, preorder_right=n - 1, 
                                    inorder_left=0, inorder_right=n - 1)
        return res

# if __name__ == "__main__":
#     s = Solution()
#     s.buildTree([3, 9, 20, 15, 7], [9, 3, 15, 20, 7])
# @lc code=end

