#
# @lc app=leetcode.cn id=130 lang=python3
#
# [130] 被围绕的区域
#

# @lc code=start
from typing import List

import pdb

class Solution:
    def __init__(self) -> None:
        ...
    
    def solve(self, board: List[List[int]]) -> None:
        def dfs(board: List[List[int]], x: int, y: int):
            if (x < 0 or x >= len(board) or y < 0 or y >= len(board[0]) or board[x][y] != 'O'):
                return
            
            board[x][y] = '#'
            dfs(board=board, x=x+1, y=y)
            dfs(board=board, x=x-1, y=y)
            dfs(board=board, x=x, y=y-1)
            dfs(board=board, x=x, y=y+1)
        
        if not len(board):
            return
        x_limit = len(board)
        y_limit = len(board[0])

        # 从边缘开始进行搜索
        # 这样能够确定最终有效的 O，这个时候的标记用其他符号
        for i in range(x_limit):
            if board[i][0] == 'O':
                dfs(board=board, x=i, y=0)
            if board[i][y_limit - 1] == 'O':
                dfs(board=board, x=i, y=y_limit-1)
        for i in range(y_limit):
            if board[0][i] == 'O':
                dfs(board=board, x=0, y=i)
            if board[x_limit - 1][i]:
                dfs(board=board, x=x_limit-1, y=i)
        
        # 对不是跟边缘拼接的 O，我们将其变更为 X
        # 对于从边缘开始出现的 O，我们将其还原
        for i in range(x_limit):
            for j in range(y_limit):
                if board[i][j] == 'O':
                    board[i][j] = 'X'
                if board[i][j] == '#':
                    board[i][j] = 'O'



# Pass rate: 11/58
# 错误的原因是没有考虑到如果 O 是从边缘包过来的会怎样
class ErrrorSolution:
    def __init__(self) -> None:
        # 上下左右
        self.directions = [(0, -1), (0, 1), (-1, 0), (1, 0)]
        self.is_circle = []


    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        def dfs(board: List[List[str]], dir: int, cur_pos: tuple):
            # 移动之后超过了边界
            pos_x = cur_pos[0] + dir[0]
            pos_y = cur_pos[1] + dir[1]
            if (pos_x >= x_limit or pos_x < 0) or (pos_y >= y_limit or pos_y < 0):
                return
            
            # 这个位置已经遍历过了
            if visited[pos_x][pos_y] is True:
                return

            visited[pos_x][pos_y] = True

            # 这里需要更多的条件判断
            if board[pos_x][pos_y] == "O":
                self.is_circle.append([pos_x, pos_y])
                print(f"is_circle: {self.is_circle}")


            # 往四个方向移动
            for d in self.directions:
                # 更改 cur_pos，从而达到 dfs 的目的
                dfs(board=board, dir=d, cur_pos=(pos_x, pos_y))

        x_limit = len(board)
        y_limit = len(board[0])
        visited = [[False for i in range(x_limit)] for j in range(y_limit)]

        visited[0][0] = True
        for d in self.directions:
            dfs(board=board, dir=d, cur_pos=(0, 0))

        # filter position
        to_filled_pos = filter(lambda x: (x[0] != 0 and x[0] != x_limit - 1) and (x[1] != 0 and x[1] != y_limit - 1), self.is_circle) 

        # fill matrix
        for t in to_filled_pos:
            board[t[0]][t[1]] = "X"


# @lc code=end

