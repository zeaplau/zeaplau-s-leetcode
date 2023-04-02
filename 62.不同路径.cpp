/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // dp: f[i][j] = f[i - 1][j] + f[i][j - 1]
        vector<vector<int>> pathMap(m, vector<int>(n));

        // only one way
        for (int i = 0; i < m; i++) {
            pathMap[i][0] = 1;
        }
        for (int i = 0; i < n; i++) {
            pathMap[0][i] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                pathMap[i][j] = pathMap[i - 1][j] + pathMap[i][j - 1];
            }
        }
        return pathMap[m - 1][n - 1];
    }
};
// @lc code=end

