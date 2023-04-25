#
# @lc app=leetcode.cn id=172 lang=python3
#
# [172] 阶乘后的零
#

# @lc code=start
'''
    首先要想到，这个和 n! 中的因子 10 的个数有关系，有多少个 10，就有
    有多少个 0
    应该考虑到使用质数相关的东西（虽然做的时候也感觉到了和
    5 有密切关系）
'''
class Solution:
    def trailingZeroes(self, n: int) -> int:
        ans = 0
        while n:
            n //= 5
            ans += n
        return ans
# @lc code=end

