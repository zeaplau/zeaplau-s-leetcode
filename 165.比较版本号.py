#
# @lc app=leetcode.cn id=165 lang=python3
#
# [165] 比较版本号
#

# @lc code=start

import pdb

class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1 = version1.split(".")
        v2 = version2.split(".")
        # 需要考虑到是否进行呢交换
        is_swap = 0

        if len(v2) > len(v1):
            v1, v2 = v2, v1
            is_swap = 1

        for idx, val in enumerate(v1):
            # 如果这个时候 idx 对比的下表超过另一个对比的长度
            # 另一个对比的值默认为 0
            v2_val = v2[idx] if idx <= len(v2) - 1 else '0'

            
            # 转化为 int 后再进行比较
            if int(val) > int(v2_val):
                return -1 if is_swap else 1
            elif int(val) < int(v2_val):
                return 1 if is_swap else -1
        return 0

# @lc code=end

