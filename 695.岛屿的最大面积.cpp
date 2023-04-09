/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int di[4] = {0, 0, -1, 1};
    int dj[4] = {1, -1, 0, 0};

    int dfs(vector<vector<int>> &grid, int cur_i, int cur_j) {
        if (cur_i < 0 || cur_j < 0 || cur_i == grid.size() || cur_j == grid[0].size() || grid[cur_i][cur_j] != 1) {
            return 0;
        }
        grid[cur_i][cur_j] = 0;
        int ans = 1;
        for (int dirIdx = 0; dirIdx < 4; dirIdx++) {
            int next_i = cur_i + di[dirIdx];
            int next_j = cur_j + dj[dirIdx];
            ans += dfs(grid, next_i, next_j);
        }
        return ans;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i != grid.size(); i++) {
            for (int j = 0; j != grid[0].size(); j++) {
                ans = max(ans, dfs(grid, i, j));
            }
        }
        return ans;
    }
};
// @lc code=end

