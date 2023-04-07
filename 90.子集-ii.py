#
# @lc app=leetcode.cn id=90 lang=python3
#
# [90] 子集 II
#

# @lc code=start
from typing import List

class Solution:
    # 回溯
    def __init__(self) -> None:
        self.res = [[]] # 默认存在空集

    def dfs(self, s_idx, cur_idx, nums: List[int]):
        # 如果这个时候要加入的值超过了数组的长度
        # 也就是说最后一个数已经加入过了
        if cur_idx > len(nums) - 1:
            return
        # 判断当前元素和之前的元素是不是一样
        if s_idx > 0 and nums[s_idx] == nums[s_idx - 1]:
            return
        self.res.append(nums[s_idx:cur_idx])
        # 进行 dfs
        # 枚举起始点后面的元素
        for i in range(len(nums[s_idx + 1:])):
            self.dfs(s_idx, s_idx + i, nums)
        ...

    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums = sorted(nums)
        # 确定起始点
        for i in range(len(nums)):
            self.dfs(i, i + 1, nums)

# @lc code=end

