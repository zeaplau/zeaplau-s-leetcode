/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> v(m + 1, vector<int>(n + 1));
        // match character: m[s_idx][p_idx] = m[s_idx - 1][p_idx - 1]
        // match '.': m[s_idx][p_idx] = m[s_idx - 1][p_idx - 1]
        // match '*': 
        //  1) s[s_idx] != p[p_idx - 1], m[s_idx][p_idx] = m[s_idx][p_idx - 2]
        //  2) s[s_idx] == p[p_idx - 1], m[s_idx][p_idx] = m[s_idx][p_idx - 2] || m[s_idx - 1][p_idx]
        for(int s_idx = 1; s_idx <= m; s_idx++) {
            for (int p_idx = 1; p_idx <= n; p_idx++) {
                if (s[s_idx - 1] == p[p_idx - 1] || p[p_idx - 1] == '.') {
                    v[s_idx][p_idx] = v[s_idx - 1][p_idx - 1];
                }
                else if (p[p_idx - 1] == '*') {
                    if (s[s_idx - 1] == p[p_idx - 2] && p[p_idx - 1] != '.') {
                        v[s_idx][p_idx] = v[s_idx][p_idx - 2];
                    } else {
                        v[s_idx][p_idx] = v[s_idx][p_idx - 2] || v[s_idx - 1][p_idx];
                    }
                }
            }
        }
        return v[m][n];
    }
};
// @lc code=end

