/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    bool rowMap[9][9];
    bool colMap[9][9];
    bool boxMap[3][3][9];
    vector<pair<int, int>> space;
    bool isValid = false;


    void dfs(vector<vector<char>>& board, int pos) {
        // 整个 board 都遍历完成，说明能够填入
        if (pos == space.size()) {
            isValid = true;
            return;
        }
        
        auto [i, j] = space[pos];
        // 针对 i, j 这个位置进行遍历（1 - 9）数字进行逐个填入尝试
        for (int digit = 0; digit < 9 && !isValid; digit++) {
            // 如果这个数字没有填入（符合游戏规则）
            if (!rowMap[i][digit] && !colMap[j][digit] && !boxMap[i / 3][j / 3][digit]) {
                rowMap[i][digit] = true;
                colMap[j][digit] = true;
                boxMap[i / 3][j / 3][digit] = true;
                board[i][j] = digit + '0' + 1;
                // 进行下一个位置的填入
                dfs(board, pos + 1);
                // 回到了递归层
                rowMap[i][digit] = false;
                colMap[j][digit] = false;
                boxMap[i / 3][j / 3][digit] = false;
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        memset(rowMap, false, sizeof(rowMap));
        memset(colMap, false, sizeof(colMap));
        memset(boxMap, false, sizeof(boxMap));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    // 记录空白的位置
                    space.emplace_back(i, j);
                } else {
                    int digit = board[i][j] - '0' - 1;
                    rowMap[i][digit] = true;
                    colMap[j][digit] = true;
                    boxMap[i / 3][j / 3][digit] = true;
                }
            }
        }
        dfs(board, 0);
    }
};
// @lc code=end

