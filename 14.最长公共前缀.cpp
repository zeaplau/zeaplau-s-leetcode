/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start

// TODO
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return string();
        }
        sort(strs.begin(), strs.end());
        auto first_str = strs.front();
        auto last_str = strs.back();
        string ans = "";
        for (int i = 0; i < first_str.size(); i++) {
            if (first_str[i] == last_str[i]) {
                ans += first_str[i];
            } else {
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

