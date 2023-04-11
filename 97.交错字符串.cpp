/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */

// @lc code=start
/*
    遇到的问题：这个 size 要先判断，然后再对 dp 复制，不然
    全为空的字符串没法过
*/


#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // 因为 0 这种情况也要考虑进去，初始化的时候要
        // 用相应的 size + 1
        auto dp = vector<vector<int>>(s1.size() + 1, vector<int>(s2.size() + 1, false));

        // 如果长度对不上，直接就不可能是插入交错
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }

        dp[0][0] = true;

        // dp[i][j] = (dp[i - 1][j] and s[i + j - 1] == s1[i - 1]) or (dp[i][j - 1] and s[i + j - 1] == s2[j - 1])
        for (int i = 0; i <= s1.size(); i++) {
            for (int j = 0; j <= s2.size(); j++) {
                // 我们要从第一个开始，因为 dp[0][0] 默认为可行
                if (i > 0) {
                    dp[i][j] |= dp[i - 1][j] && s3[i + j - 1] == s1[i - 1];
                }
                if (j > 0) {
                    dp[i][j] |= dp[i][j - 1] && s3[i + j - 1] == s2[j - 1];
                }
            }
        }
        return dp[s1.size()][s2.size()];
    }
};
// @lc code=end

