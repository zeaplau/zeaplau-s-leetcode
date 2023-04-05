#
# @lc app=leetcode.cn id=79 lang=python3
#
# [79] 单词搜索
#

# @lc code=start
from typing import List


class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]

        def check(i:int, j:int, k:int) -> bool:
            # 当前单词不匹配，说明后面的都不匹配
            if board[i][j] != word[k]:
                return False
            # 如果这个时候找到的单词已经没有了
            # 那就返回成功
            if k == len(word) - 1:
                return True

            # 对访问的节点进行标记
            visited.add((i, j))
            result = False
            # 各个方向找一次
            for di, dj in directions:
                newi, newj = i + di, j + dj
                # 判断新的坐标有没有过界
                if 0 <= newi < len(board) and 0 <= newj < len(board[0]):
                    # 判断新的坐标有没有走过，如果没有走过那就检查一下加上这个坐标
                    # 是否能组成给定的单词
                    if (newi, newj) not in visited:
                        # FIXME 这里写错了，这个地方不用加，因为进去 `check` 
                        # 之后会再标记
                        # visited.add((newi, newj))
                        if check(newi, newj, k + 1):
                            result = True
                            break
            
            # 这个起始坐标检查完了，能走到这里说明不能满足给定的单词
            # 那么就恢复现场，走下一个坐标
            visited.remove((i, j))
            return result

        row, col = len(board), len(board[0])
        visited = set()
        for i in range(row):
            for j in range(col):
                if check(i, j, 0):
                    return True
        
        return False


# @lc code=end

