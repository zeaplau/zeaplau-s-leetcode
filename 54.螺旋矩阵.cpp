/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
#include <vector>

using namespace std;


class Solution {
public:
    // 不同的方向
    static constexpr int directions[4][2] = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}
    };
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return {};
        }
        // 边界
        int rows = matrix.size();
        int cols = matrix[0].size();
        // 记录哪些数组已经被记录过了
        vector<vector<bool>> visited(rows, vector<bool>(cols));
        int amount = rows * cols;
        // 返回的数字
        vector<int> order(amount);
        int directionIdx = 0;
        int rowIdx = 0;
        int colIdx = 0;
        for (int i = 0; i < amount; i++) {
            order[i] = matrix[rowIdx][colIdx];
            visited[rowIdx][colIdx] = true;
            // 看一下下一步要移到哪里去，超过边界就要跳到下一个方向去
            int nextRowIdx = rowIdx + directions[directionIdx][0];
            int nextColIdx = colIdx + directions[directionIdx][1];
            if (nextRowIdx < 0 || nextRowIdx >= rows || nextColIdx < 0 || nextColIdx >= cols || visited[nextRowIdx][nextColIdx]) {
                directionIdx = (directionIdx + 1) % 4;
            }
            // 更新下标
            rowIdx += directions[directionIdx][0];
            colIdx += directions[directionIdx][1];
        }
        return order;
    }
};
// @lc code=end

