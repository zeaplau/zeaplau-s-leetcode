#
# @lc app=leetcode.cn id=42 lang=python3
#
# [42] 接雨水
#

# @lc code=start
from typing import List

class Solution:
    def trap(self, height: List[int]) -> int:
        ans = 0
        stack = []
        cur = 0
        while cur < len(height):
            # 这里 pushin 的是下标，push 高度也是可以的
            while len(stack) != 0 and height[cur] > height[stack[-1]]:
                h = height[stack[-1]]
                stack.pop(-1)
                # 这个时候判断栈里面是不是没有墙了，如果没有墙说明之前 pop 出去的是最后一堵墙，不用计算
                if len(stack) == 0:
                    break
                distance = cur - stack[-1] - 1
                min_wall = min(height[stack[-1]], height[cur])
                ans = ans + distance * (min_wall - h)
            stack.append(cur)
            print(stack)
            cur += 1
        return ans

# @lc code=end

