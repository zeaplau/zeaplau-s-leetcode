#
# @lc app=leetcode.cn id=39 lang=python3
#
# [39] 组合总和
#

# @lc code=start
from typing import List

class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        ans = []
        def dfs(candidates: List[int], begin_idx: int, end_idx: int, target: int, path: List[int]) -> List[List[int]]:
            if target < 0:
                return
            if target == 0:
                ans.append(path)
                return

            # enumerate each element in the rest candidates
            for i in range(begin_idx, end_idx):
                # since the element can be used repeatly, so the begin_idx is still `i`, which mean itself
                dfs(candidates=candidates, begin_idx=i, end_idx=end_idx, target=target-candidates[i], path=path+[candidates[i]])
        # the candidates given is empty
        if len(candidates) == 0:
            return []

        path = []
        dfs(candidates=candidates, begin_idx=0, end_idx=len(candidates), target=target, path=path)
        return ans




# @lc code=end

