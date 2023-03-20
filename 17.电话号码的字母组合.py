#
# @lc app=leetcode.cn id=17 lang=python3
#
# [17] 电话号码的字母组合
#

# @lc code=start
class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if digits == "":
            return []
        res = []
        p_map = {
            '2': ['a', 'b', 'c'],
            '3': ['d', 'e', 'f'],
            '4': ['g', 'h', 'i'],
            '5': ['j', 'k', 'l'],
            '6': ['m', 'n', 'o'],
            '7': ['p', 'q', 'r', 's'],
            '8': ['t', 'u', 'v'],
            '9': ['w', 'x', 'y', 'z']
        }

        def backtrace(conbination, nextdight):
            if len(nextdight) == 0:
                res.append(conbination)
            else:
                for letter in p_map[nextdight[0]]:
                    backtrace(conbination=conbination + letter, nextdight=nextdight[1:])
        backtrace("", nextdight=digits)
        return res
# @lc code=end

