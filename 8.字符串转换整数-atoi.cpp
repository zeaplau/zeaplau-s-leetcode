/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
#include <limits.h>
#include <stdint.h>
#include <string>
#include <limits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int res = 0;
        int sign = 1;
        int len = s.size();
        int idx = 0;
        
        // Prefix blank
        while (idx < len && s[idx] == ' ') {
            idx++;
        }
        if (idx == len) {
            return 0;
        } 

        // + -
        if (s[idx] == '+') {
            sign = 1;
            idx++;
        } else if (s[idx] == '-') {
            sign = -1;
            idx++;
        }

        // digits
        while (idx < len && (s[idx] >= '0' && s[idx] <= '9')) {
            int digit = s[idx] - '0';
            // res * 10 + digit > INT_MAX
            if (res > (INT_MAX - digit) / 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            res = res * 10 + digit;
            idx++;
        }
        return sign * res;
    }
};
// @lc code=end

