#
# @lc app=leetcode.cn id=80 lang=python3
#
# [80] 删除有序数组中的重复项 II
#

# @lc code=start
from typing import List

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        '''
        主要思想是，两个指针同步走，如果遇到有不等的 value，那么就移动快的指针，慢的指针代表要取代的位置
        为什么对比前两个，因为题目要求最多保留两个
        '''

        # 如果是数组包含少于两个元素，那就直接返回
        if len(nums) <= 2:
            return len(nums)
        
        # slow 代表处理过后的数组指向的位置
        # fast 代表正在处理的数据
        # slow 和 fast 在同一起跑线，但是比较的时候要注意，slow 需要往前推 2 个
        slow = 2
        fast = 2
        for fast in range(2, len(nums)):
            # 如果和两个前的不等，说明包含了两个以上的重复，直接替换
            if nums[fast] != nums[slow - 2]:
                nums[slow] = nums[fast]
                slow += 1
        return slow

# @lc code=end

