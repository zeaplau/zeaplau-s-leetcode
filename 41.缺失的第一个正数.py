#
# @lc app=leetcode.cn id=41 lang=python3
#
# [41] 缺失的第一个正数
#

# @lc code=start

import sys

class Solution(object):
    def swap(self, nums, idx1, idx2):
        nums[idx1], nums[idx2] = nums[idx2], nums[idx1]

    def firstMissingPositive(self, nums):
        """
        整体思路是一个哈希函数
        可以把对应数字放到自己的下标 v - 1 下面，直接将这个值覆盖，然后再进行遍历
        如果遇到了它的值不等于下标的那个数，那就是要找的缺失的第一个正数
        实际上就是一个简单的哈希函数，就是将数值为 v 的数映射到下标为 v - 1 这个位置去
        比如 3 -> idx 2, 4 -> idx 4
        :type nums: List[int]
        :rtype: int
        """
        size = len(nums)
        for i in range(size):
            # 判断是不是索引，然后再判断是不是在正确的位置上
            while 1 <= nums[i] <= size and nums[i] != nums[nums[i] - 1]:
                self.swap(nums, i, nums[i] - 1)
        
        for i in range(size):
            if i + 1 != nums[i]:
                return i + 1
        return size + 1

# @lc code=end

