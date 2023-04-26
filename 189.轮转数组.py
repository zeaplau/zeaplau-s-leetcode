#
# @lc app=leetcode.cn id=189 lang=python3
#
# [189] 轮转数组
#

# @lc code=start
from typing import List

import pdb

class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        def reverse(nums: List[int], left: int, right: int):
            l, r = left, right
            while l < r:
                nums[l], nums[r] = nums[r], nums[l]
                l = l + 1
                r = r - 1
        
        n = len(nums)
        k %= n
        reverse(nums=nums, left=0, right=n - 1)
        reverse(nums=nums, left=0, right=k - 1)
        reverse(nums=nums, left=k, right=n - 1)


# @lc code=end

