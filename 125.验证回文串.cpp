/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start

/*
    left < right 这个是必须的
*/


#include <ctype.h>
#include <string>

using namespace std;

class Solution {
public:
    // 判断传入的字符是不是字母
    bool isalpha(char c) {
        char lower_c = tolower(c);
        return (lower_c >= 'a' && lower_c <= 'z');
    }

    // 判断传入的字符是不是数字
    bool isnum(char c) {
        return (c >= '0' && c <= '9');
    }

    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            // 如果左指针遇到的字符不是字母或者数字
            while (left < right && !(isalpha(s[left]) || isnum(s[left]))) {
                ++left;
            }

            // 如果右指针遇到的字符不是字母或者数字
            while (left < right && !(isalpha(s[right]) || isnum(s[right]))) {
                --right;
            }

            // 进行对比
            if (left < right) {
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }
                ++left;
                --right;
            }
        }
        return true;
    }
};
// @lc code=end

