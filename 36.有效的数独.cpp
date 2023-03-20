/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
#include <unordered_map>
#include <vector>

using namespace std;


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 9 行 9 个数字
        int rowMap[9][9];
        // 9 列 9 个数字
        int colMap[9][9];
        // 3 列 3 行 box，9 个数字
        int boxMap[3][3][9];
        
        memset(rowMap, 0, sizeof(rowMap));
        memset(colMap, 0, sizeof(colMap));
        memset(boxMap, 0, sizeof(boxMap));

        // 行
        for (int i = 0; i < 9; i++) {
            // 列
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c != '.') {
                    int idx = c - '0' - 1;
                    rowMap[i][idx] += 1;
                    colMap[j][idx] += 1;
                    boxMap[i / 3][j / 3][idx] += 1;
                    if (rowMap[i][idx] > 1 || colMap[j][idx] > 1 || boxMap[i / 3][j / 3][idx] > 1) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end

