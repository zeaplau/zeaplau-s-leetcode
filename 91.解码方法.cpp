/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
/*
    一道 dp，仔细想比较容易想明白的做法，需要注意的是空字符串也有一种方法
    一开始以为用 map 来分类算，实际上还是得 dp
*/
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            // 只考虑一位数是有效的
            // 这个数有效（不为零），那就将这个数的有效情况加入
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }
            // 这个时候考虑两位数
            // 判断这两位数是不是正确的
            if (i > 1 && s[i - 2] != '0' && ((s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26)) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};
// @lc code=end

