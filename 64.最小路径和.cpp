/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> map(m, vector<int>(n));
        // initial, actuall we do not need to initial here
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                map[i][j] = grid[i][j];
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    continue;
                } else if (i == 0) {
                    // The value is acquired from left
                    map[i][j] = map[i][j - 1] + map[i][j];
                } else if (j == 0) {
                    // The value is acquired from upper one
                    map[i][j] = map[i - 1][j] + map[i][j];
                } else {
                    // In the middle, the added value get from the min one 
                    // from upper or the left
                    map[i][j] = min(map[i - 1][j], map[i][j - 1]) + map[i][j];
                }
            }
        }
        return map[m - 1][n - 1];
    }
};
// @lc code=end

