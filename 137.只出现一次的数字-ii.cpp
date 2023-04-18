/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int total = 0;
            for (auto &num : nums) {
                // 得到第 i 位的二进制位
                total += ((num >> i) & 1);
            }
            if (total % 3) {
                // 如果这个 total 能被 3 求余
                // 说明在这一位置上积攒了很多 3 的倍数的数字
                // 这里如果有一个 1 的数字，会出现一个 3*n + 1 的情况
                ans |= (1 << i);
            }
        }
        return ans;
    }
};
// @lc code=end

