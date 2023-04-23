#
# @lc app=leetcode.cn id=153 lang=python3
#
# [153] 寻找旋转排序数组中的最小值
#

# @lc code=start
from typing import List

class Solution:
    def findMin(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1
        while left < right:
            # 获取 [left, right] 之间的中间节点
            mid = left + (right - left) // 2
            # 直接对比右边区间的即可，思路有点像旋转数组搜索的那一题
            # 如果最右边的值比中间的值还要大，说明中间到最右边的区间是逐步
            # 递增的，所以对左边进行搜索
            if nums[mid] < nums[right]:
                right = mid
            # 如果中间的值比右边的值要大，说明中间遇到了一个极值点，所以搜索
            # 右边
            else:
                left = mid + 1
        return nums[left]
# @lc code=end

