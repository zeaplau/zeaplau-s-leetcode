#
# @lc app=leetcode.cn id=31 lang=python3
#
# [31] 下一个排列
#

# @lc code=start
from typing import List


class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        def reverse(nums, i, j):
            while i < j:
                nums[i],nums[j] = nums[j], nums[i]
                i += 1
                j -= 1


        first_index = -1
        n = len(nums)
        
        # 找到最大的下标满足 nums[k] < nums[k + 1]
        for i in range(n - 2, -1, -1):
            if nums[i] < nums[i + 1]:
                first_index = i
                break
        
        # Not found
        if first_index == -1:
            reverse(nums, 0, n - 1)
            return 

        # 找出另一个最大的索引，满足 nums[i] > nums[first_idx]
        second_idx = -1
        for i in range(n - 1, first_index, -1):
            if nums[i] > nums[first_index]:
                second_idx = i
                break
        
        # 交换后再反转
        nums[first_index], nums[second_idx] = nums[second_idx], nums[first_index]
        reverse(nums, first_index + 1, n - 1)

# @lc code=end

