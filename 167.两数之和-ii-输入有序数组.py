#
# @lc app=leetcode.cn id=167 lang=python3
#
# [167] 两数之和 II - 输入有序数组
#

# @lc code=start
'''
    记住不是返回下标，而是在数组里面的 第几个 数字
'''
from typing import List

class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        l, r = 0, len(numbers) - 1
        while l < r:
            sum = numbers[l] + numbers[r]
            # 如果求出的和比 target 还要小，说明要小的要往右边走变大
            if (sum < target):
                l = l + 1
            # 如果求出来的和比 target 还要大，说明大的要往左边走变小
            elif sum > target:
                r = r - 1
            else:
                return [l + 1, r + 1]
        return [-1, -1]
# @lc code=end

