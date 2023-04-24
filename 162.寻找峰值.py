#
# @lc app=leetcode.cn id=162 lang=python3
#
# [162] 寻找峰值
#

# @lc code=start
from typing import List

class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        l, r = 0, len(nums) - 1

        while l < r:
            mid = l + ((r - l) >> 1)
            if nums[mid] < nums[mid + 1]:
                # 去右区间
                l = mid + 1
            else:
                # 去左区间
                r = mid
        return l
# @lc code=end

