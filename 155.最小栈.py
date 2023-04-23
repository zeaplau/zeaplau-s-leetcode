#
# @lc app=leetcode.cn id=155 lang=python3
#
# [155] 最小栈
#

# @lc code=start
class MinStack:

    def __init__(self):
        self.min_vals = list() # 单调栈
        self.stack = list() # 实际的栈


    def push(self, val: int) -> None:
        if len(self.min_vals) == 0:
            self.min_vals.append(val)
        else:
            # 更新最小值
            # 这里的等于是必须的，因为有可能 getMin 两次会没值
            if val <= self.min_vals[-1]:
                self.min_vals.append(val)
        self.stack.append(val)


    def pop(self) -> None:
        if self.top() == self.min_vals[-1]:
            self.min_vals.pop()
        self.stack.pop()


    def top(self) -> int:
        return self.stack[-1]


    def getMin(self) -> int:
        return self.min_vals[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
# @lc code=end

