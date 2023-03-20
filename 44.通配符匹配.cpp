/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */

// @lc code=start
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int s_size = s.length();
        int p_size = p.length();
        vector<vector<int>> dp (s_size + 1, vector<int>(p_size + 1, 0));

        dp[0][0] = 1; // length of `s` and `p` is 0
        
        // Cuz only '*' can match the empty string
        // only when pre-j charactors are all '*', dp[0][j] is true
        for (int i = 1; i <= p_size; i++) {
            if (p[i - 1] == '*') {
                dp[0][i] = 1;
            } else {
                break;
            }
        }

        for (int i = 1; i <= s_size; i++) {
            for (int j = 1; j <= p_size; j++) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
                } else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[s_size][p_size];
    }
};
// @lc code=end

