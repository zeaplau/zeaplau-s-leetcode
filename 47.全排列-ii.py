#
# @lc app=leetcode.cn id=47 lang=python3
#
# [47] 全排列 II
#

# @lc code=start
from typing import List

class Solution:
    def __init__(self) -> None:
        self.res = []

    def dfs(self, permuate_res: List[int], nums: List[int], checked: List[int]):
        if len(permuate_res) == len(nums):
            self.res.append(permuate_res)
            return
        
        for i in range(len(nums)):
            # 已经使用过这个数字了
            if checked[i] == 1:
                continue
            # 如果这个数字和前面的一样（因为后续将其变回为 0， 所以条件检查里面还是 checked[i - 1] == 0）
            if i > 0 and nums[i] == nums[i - 1] and checked[i - 1] == 0:
                continue
            checked[i] = 1
            self.dfs(permuate_res=permuate_res + [nums[i]], nums=nums, checked=checked)
            checked[i] = 0

    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        checked = [0] * len(nums)
        self.dfs([], nums=nums, checked=checked)
        return self.res

# @lc code=end

