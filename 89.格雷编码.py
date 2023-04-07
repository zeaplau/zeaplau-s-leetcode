#
# @lc app=leetcode.cn id=89 lang=python3
#
# [89] 格雷编码
#

# @lc code=start
from typing import List

# 这个不是很懂
class Solution:
    def grayCode(self, n: int) -> List[int]:
        # 第一个数肯定是 0
        res, head = [0], 1
        # 计算 n 位的编码
        for i in range(n):
            for j in range(len(res) - 1, -1, -1):
                res.append(head + res[j])
            head <<= 1
        return res
# @lc code=end

