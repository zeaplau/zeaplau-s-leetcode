#
# @lc app=leetcode.cn id=151 lang=python3
#
# [151] 反转字符串中的单词
#

# @lc code=start
class Solution:
    def reverseWords(self, s: str) -> str:
        words = list(filter(lambda x: x != '', s.split(' ')))
        return ' '.join(words[::-1])
# @lc code=end

