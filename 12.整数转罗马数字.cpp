/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<string> char_vec = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> value_vec = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string ans = "";
        int c_num = num;
        for (int i = 0; i < 13; i++) {
            while (c_num >= value_vec[i]) {
                ans += char_vec[i];
                c_num -= value_vec[i];
            }
        }
        return ans;
    }
};
// @lc code=end

