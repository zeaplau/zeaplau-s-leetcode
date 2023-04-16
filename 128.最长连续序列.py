#
# @lc app=leetcode.cn id=128 lang=python3
#
# [128] 最长连续序列
#

# @lc code=start
'''
    其实就是往中间填坑，更好的解法应该使用并查集
'''

from typing import List

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        res = 0
        dic = {}
        for num in nums:
            if num not in dic:
                left = dic.get(num - 1, 0)
                right = dic.get(num + 1, 0)

                dic[num] = 1
                length = 1 + left + right
                res = max(res, length)
                # 这里就是线段，往左边和右边更新 length，表明到
                # [num - left, num + right] 区间内的长度都是 length
                dic[num - left] = length
                dic[num + right] = length

        return res

# @lc code=end

