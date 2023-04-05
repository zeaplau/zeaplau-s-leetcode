#
# @lc app=leetcode.cn id=81 lang=python3
#
# [81] 搜索旋转排序数组 II
#

# @lc code=start
from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        """
            数组中存在重复，可能会有 nums[l] == nums[mid] == nums[r] 的情况，所以
        """
        res = len(list(
            filter(lambda x: x == target, nums)
        )) > 0
        return res
# @lc code=end

