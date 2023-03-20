/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 需要了解罗马数字的规则
    // 小数字在大数字的左边，那么就要减去这个小数字（或者将这个数字的符号取反）
    int romanToInt(string s) {
        unordered_map<char, int> m = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},{'C', 100}, 
            {'D', 500}, {'M', 1000}
        };
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            int value = m[s[i]];
            if (i < s.size() - 1 && value < m[s[i + 1]]) {
                ans -= value;
            } else {
                ans += value;
            }
        }
        return ans;
    }
};
// @lc code=end

