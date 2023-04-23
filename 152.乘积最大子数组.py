#
# @lc app=leetcode.cn id=152 lang=python3
#
# [152] 乘积最大子数组
#

# @lc code=start
'''
    当前的最大值 imax = max(imax * nums[i], nums[i])
    但是需要注意的是，数组里存在负数，会导致最小值变成最大值
    因此需要保持一个数来确定当前的最小值，当遇到负数的时候两者进行交换
'''
from typing import List

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        max_val = -11
        imax = 1
        imin = 1
        for i in range(len(nums)):
            # 因为存在负数，所以可能会有最大的变成最小
            # 最小的编程最大这种情况出现
            if nums[i] < 0:
                imax, imin = imin, imax
            imax = max(imax * nums[i], nums[i])
            imin = min(imin * nums[i], nums[i])
            
            # 获得最大的值
            max_val = max(max_val, imax)
        return max_val
# @lc code=end

