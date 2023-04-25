#
# @lc app=leetcode.cn id=187 lang=python3
#
# [187] 重复的DNA序列
#

# @lc code=start
'''
    每 10 个地截获字符串，然后使用一个哈希表来记录每次截取出现的次数
'''
from typing import List
from collections import defaultdict

class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        hash_map = defaultdict(int)
        ans = []
        for i in range(len(s) - 9):
            sub = s[i : i + 10]
            hash_map[sub] += 1
            if hash_map[sub] == 2:
                ans.append(sub)
        return ans

# @lc code=end

