/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0.0) {
            return 0.0;
        }
        long b = n;
        double res = 1.0;
        if (b < 0) {
            x = 1 / x;
            b = -b;
        }

        while (b > 0) {
            // 判断二进制最右的一位是不是 1，如果是 1 那就乘上去
            if ((b & 1) == 1) {
                res *= x;
            }
            // 不断计算 x^1, x^2, x^3 ... 的值
            x *= x;
            // 移位操作
            b >>= 1;
        }
        return res;
    }
};
// @lc code=end

