/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
#include <vector>

using namespace std;


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m_ = obstacleGrid.size();
        int n_ = obstacleGrid[0].size();
        vector<vector<int>> pathMap(m_, vector<int>(n_));

        // first col
        for (int i = 0; i < m_ && obstacleGrid[i][0] == 0; i++) {
            pathMap[i][0] = 1;
        }
        // first row
        for (int i = 0; i < n_ && obstacleGrid[0][i] == 0; i++) {
            pathMap[0][i] = 1;
        }

        // dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
        for (int i = 1; i < m_; i++) {
            for (int j = 1; j < n_; j++) {
                // if obstacleGrid[i][j] is 1, mean that impossibile
                // to access
                if (obstacleGrid[i][j] == 0) {
                    pathMap[i][j] = pathMap[i - 1][j] + pathMap[i][j - 1];
                }
            }
        }
        return pathMap[m_ - 1][n_ - 1];
    }
};
// @lc code=end

