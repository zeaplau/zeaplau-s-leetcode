/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        long res = 0;
        int i = x;
        while (i != 0) {
            res = res * 10 + i % 10;
            i = i / 10;
        }
        return res == x ? true : false;
    }
};
// @lc code=end

