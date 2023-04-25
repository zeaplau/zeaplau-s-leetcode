#
# @lc app=leetcode.cn id=168 lang=python3
#
# [168] Excel表列名称
#

# @lc code=start
'''
    26 进制转换
    正常的进制转换是，先 '%' 得到最后一位，然后对给定的数进行 '//' 操作
    但是这一题需要注意的是，转换是从 1 开始的，所以最开始要 '-1' 对整个
    数进行偏移
'''

class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        res = ""
        while columnNumber:
            columnNumber = columnNumber - 1
            # 记得最后要 reverse，因为这里是从前往后添加的
            res += chr(columnNumber % 26 + ord('A'))
            columnNumber = columnNumber // 26
        return res[::-1]
# @lc code=end

