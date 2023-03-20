#
# @lc app=leetcode.cn id=38 lang=python3
#
# [38] 外观数列
#

# @lc code=start
class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return "1"
        if n == 2:
            return "11"
        
        # 获得之前的数字
        prev_str = self.countAndSay(n - 1)

        ans = ""
        count = 1
        # 因为要和后面一个对比，所以是 len(prev_str) - 1
        for i in range(len(prev_str) - 1):
            if prev_str[i] == prev_str[i + 1]:
                count += 1
            else:
                ans += str(count) + prev_str[i]
                # count 归 1 用于重新统计
                count = 1
        ans += str(count) + prev_str[-1]
        return ans

# @lc code=end

