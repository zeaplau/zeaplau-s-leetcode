/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int maxans = 0;
        int n = s.size();
        vector<int> dp(n, 0);

        // 注意这里是从下标 1 开始
        for (int i = 1; i < n; i++) {
            // 如果遇到了 ')'，说明遇到了可能匹配的字符
            if (s[i] == ')') {
                // 如果 ')' 的前一个字符是 '('，说明遇到了匹配的情况
                if (s[i - 1] == '(') {
                    // 判断是为了防止越界，dp[i - 2] 考虑到之前的有效字符串的情况
                    dp[i] = i >= 2 ? dp[i - 2] + 2 : 0 + 2;
                    // 如果这个时候遇到的情况是连续的 '))'，并且发现第一个 ')' 存在匹配
                } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    int toAdd = 0;
                    // 这个时候说明前面存在有效的子串，这个时候的添加数量是前方有效字符串的数量
                    if (i - dp[i - 1] >= 2) {
                        toAdd = dp[i - dp[i - 1] - 2];
                    } else {
                        toAdd = 0;
                    }
                    dp[i] = dp[i - 1] + toAdd + 2;
                } 
            }
            maxans = std::max(maxans, dp[i]);
        }
        return maxans;
    }
};
// @lc code=end

