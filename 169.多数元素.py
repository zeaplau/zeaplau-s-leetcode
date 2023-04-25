#
# @lc app=leetcode.cn id=169 lang=python3
#
# [169] 多数元素
#

# @lc code=start
from typing import List

import pdb

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        cur_record = None
        count = 0
        for i, v in enumerate(nums):
            # At the start
            if cur_record is None:
                count += 1
                cur_record = v
                print(f"1: {count} {cur_record} {v}")
                continue

            if cur_record == v:
                count += 1
            else:
                # We first sub '1' before we mean different number
                count -= 1
                # If the count is '0', mean that the value recording
                # need to be changed
                if count == 0:
                    cur_record = v
                    count += 1
                    continue
            print(f"2: {count} {cur_record} {v}")
        print(f"cur_record: {cur_record}")
        return cur_record

# s = Solution()
# s.majorityElement([2, 3, 3, 1, 1, 2, 2])
# @lc code=end

