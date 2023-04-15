/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // 一共有 numRows 个层
        vector<vector<int>> v(numRows);

        for (int i = 0; i < numRows; i++) {
            v[i].resize(i + 1, 1);
            // 每层有 i 个数
            for (int k = 1; k < i; k++) {
                // 取上一层的 下方 和 左上方
                v[i][k] = v[i - 1][k] + v[i - 1][k - 1];
            }
        }
        return v;
    }
};
// @lc code=end

