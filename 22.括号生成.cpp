/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> res;
    void dfs(const string& str, int left, int right) {
        if (left < 0 || left > right) {
            return;
        }
        if (left == 0 && right == 0) {
            res.push_back(str);
            return;
        }
        dfs(str + "(", left - 1, right);
        dfs(str + ")", left, right - 1);
    }

    vector<string> generateParenthesis(int n) {
        dfs("", n, n);
        return res;
    }
};
// @lc code=end

