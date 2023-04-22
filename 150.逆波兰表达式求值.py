#
# @lc app=leetcode.cn id=150 lang=python3
#
# [150] 逆波兰表达式求值
#

# @lc code=start
'''
    需要注意的是， '/' 和 '-' 要注意次序问题（这题还有将 '/' 的结果转化为 整数）
'''

from typing import List, Optional

import pdb

class Solution:
    def plus(self, val1: int, val2: int) -> int:
        return val1 + val2
    
    def sub(self, val1: int, val2: int) -> int:
        return val1 - val2

    def multi(self, val1: int, val2: int) -> int:
        return val1 * val2
    
    def divide(self, val1: Optional[float], val2: Optional[float]) -> Optional[float]:
        return val1 / val2

    def evalRPN(self, tokens: List[str]) -> int:
        signs = ['+', '-', '*', '/']
        stack = []

        for idx, val in enumerate(tokens):
            if val not in signs:
                stack.append(int(val))
            else:
                sign = val
                val1 = stack.pop()
                val2 = stack.pop()
                if sign == '+':
                    res = self.plus(val1, val2)
                    stack.append(res)
                if sign == '-':
                    res = self.sub(val2, val1)
                    stack.append(res)
                if sign == '*':
                    res = self.multi(val1, val2)
                    stack.append(res)
                if sign == '/':
                    res = self.divide(val2, val1)
                    stack.append(int(res))

        return stack.pop()

# if __name__ == "__main__":
#     s = Solution()
#     print(s.evalRPN(["4","13","5","/","+"]))

# @lc code=end

