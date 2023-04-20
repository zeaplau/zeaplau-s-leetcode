#
# @lc app=leetcode.cn id=139 lang=python3
#
# [139] 单词拆分
#

# @lc code=start
'''
    使用 dp[i] 代表前 i 个字符可否利用 wordDict 里面的单词构成;
    dp[0] 的意义是空字符，空字符肯定是可以拼接而成的，所以一定为 True;
    dp[i + 1] 必须检查 [j:i + 1] 内部的全部能够构成字典里面单词，j 的范围是
    i + 1 -> 1，如果能够构成，那就设为 True;
'''

from typing import List


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        wordset = set(wordDict)
        n = len(s)
        # 因为要考虑到空串，所以要加多一个位置来存储，所以开辟的空间是 (n + 1)
        dp = [False] * (n + 1)
        # 如果没有字符串，那肯定可以拼成
        dp[0] = True
        for i in range(1, n + 1):
            j = i
            while j >= 1 and not dp[i]:
                substr = s[j - 1:i]
                if substr in wordset:
                    dp[i] = dp[j - 1]
                j = j - 1
        return dp[n]
# @lc code=end

