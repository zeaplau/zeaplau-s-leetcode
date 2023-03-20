#
# @lc app=leetcode.cn id=40 lang=python3
#
# [40] 组合总和 II
#

# @lc code=start
from typing import List


class Solution:
    def __init__(self) -> None:
        self.ans = []

    def dfs(self, candidates: List[int], target: int, begin: int, end: int, path: List[int]) -> List[List[int]]:
        # condition
        if target < 0:
            return
        if target == 0:
            self.ans.append(path)
            return
        
        # cannot be used repeatly
        for idx in range(begin, end):
            # no need to continue
            if candidates[idx] > target:
                break
            # skip the same value, cut left here
            if idx > begin and candidates[idx - 1] == candidates[idx]:
                continue
            self.dfs(candidates=candidates, target=target-candidates[idx], begin=idx+1, end=end, path=path+[candidates[idx]])

    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        if len(candidates) == 0:
            return []
        # the candidates in order is the prerequisite of cutting
        candidates.sort()
        path = []
        self.dfs(candidates=candidates, target=target, begin=0, end=len(candidates), path=path)
        return self.ans
# @lc code=end

