#
# @lc app=leetcode.cn id=59 lang=python3
#
# [59] 螺旋矩阵 II
#

# @lc code=start
class Solution(object):
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        l, r, t, b = 0, n - 1, 0, n - 1
        res = [[0 for _ in range(n)] for _ in range(n)]
        # [行][列]
        filled_num, target = 1, n * n
        while filled_num <= target:
            for i in range(l, r + 1):
                res[t][i] = filled_num
                filled_num += 1
            t += 1
            for i in range(t, b + 1):
                res[i][r] = filled_num
                filled_num += 1
            r -= 1
            for i in range(r, l - 1, -1):
                res[b][i] = filled_num
                filled_num += 1
            b -= 1
            for i in range(b, t - 1, -1):
                res[i][l] = filled_num
                filled_num += 1
            l += 1
        return res

# @lc code=end

