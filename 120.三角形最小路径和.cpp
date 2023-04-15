/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
/*
    记 f 为走到 第 i 行 第 j 列 的最短路径总和
    最后的结果是从上一层过来的
    转移方程：
        f[i][j] = min(f[i-1][j-1], f[i-1][j]) + c[i][j]
        f[i][j] = f[i - 1][0] + c[i][0] if j == 0
        f[i][j] = f[i - 1][i - 1] + c[i][i] if j == i
*/
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < n; i++) {
            int level_size = triangle[i].size();

            // 在最左边的时候，这个数只能从上一层的最左边过来
            dp[i][0] = dp[i - 1][0] + triangle[i][0];

            // dp 公式
            for (int j = 1; j < level_size; j++) {
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            }

            // 在最右边的时候，这个数同样的只能从上一层的最右边的数过来
            dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
        }
        // min_element 是求 范围间的最小元素
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};
// @lc code=end

