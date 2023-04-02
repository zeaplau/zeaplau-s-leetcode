/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
#include <algorithm>
#include <exception>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        // 先将两个都翻转，就不用填充数字了
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        // 找到最长的序列
        int n = max(a.size(), b.size());
        int carry = 0;

        for (size_t i = 0; i < n; i++) {
            if (i < a.size()) {
                if (a[i] == '1') {
                    carry += 1;
                } else {
                    carry += 0;
                }
            }
            if (i < b.size()) {
                if (b[i] == '1') {
                    carry += 1;
                } else {
                    carry += 0;
                }
            }
            // 如果这个时候的 carry 是 1 或者 3，肯定留下一个 1
            if (carry % 2 == 1) {
                ans.push_back('1');
            } else {
                ans.push_back('0');
            }
            // 考虑到值 2 和 3，这个时候进行反转
            carry = carry / 2;
        }

        if (carry) {
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

