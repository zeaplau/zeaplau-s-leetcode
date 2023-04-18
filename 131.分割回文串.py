#
# @lc app=leetcode.cn id=131 lang=python3
#
# [131] 分割回文串
#

# @lc code=start

# TODO 今晚回去搞明白这个
from typing import List
from copy import deepcopy

class Solution:
    def partition(self, s: str) -> List[List[str]]:
        n = len(s)
        dp = [[True for i in range(n)] for j in range(n)]

        # 如果是回文字符，那么里面包着的肯定也是回文
        # dp 的含义是：[i, j] 是回文字符串，注意是闭区间
        # dp[i][j] = dp[i + 1][j - 1] and s[i] == s[j]
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                dp[i][j] = dp[i + 1][j - 1] and s[i] == s[j]
        print(f"dp: {dp}")
        
        res = list()
        ans = list()

        def dfs(l: int):
            # 到了末尾，那就将收集到的答案放进
            # 要返回的结果里面
            if l == n:
                res.append(ans[:])
                return

            # 这里开始遍历 从 l 到 i 是否构成回文，如果构成那就丢到 ans 中
            for k in range(l, n):
                if dp[l][k]:
                    ans.append(s[l:k + 1])
                    # 查看下一个是不是
                    dfs(k + 1)
                    # 因为还要探查下一个，所以要还原现场
                    ans.pop()
        dfs(0)
        print(f"res: {res}")
        return res

# @lc code=end

