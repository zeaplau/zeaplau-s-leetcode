#
# @lc app=leetcode.cn id=74 lang=python3
#
# [74] 搜索二维矩阵
#

# @lc code=start
from typing import List

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m, n = len(matrix), len(matrix[0])

        # first binary search
        l, r = 0, m - 1
        while l < r:
            mid = (l + r + 1) >> 1
            # the middle value smaller than target means that 
            # the target value in the right part, move left
            if matrix[mid][0] <= target:
                l = mid
            # in the left part, move right
            else:
                r = mid - 1

        row = r
        if matrix[row][0] == target:
            return True
        if matrix[row][0] > target:
            return False

        l, r = 0, n - 1
        while l < r:
            mid = (l + r + 1) >> 1
            # hit the target, return True
            if matrix[row][mid] == target:
                return True
            # in the right part
            elif matrix[row][mid] < target:
                l = mid
            else:
            # in the left part
                r = mid - 1
        return False


# @lc code=end

