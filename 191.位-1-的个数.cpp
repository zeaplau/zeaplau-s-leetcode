/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start

/*
    陷入了一个误区，这里一定要移动 '1' 的位数
    移动 n 的位数会导致结果一直为 1，所以没办法统计
*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        for (int i = 0; i < 32; i++) {
            // 将 n 和移动 i 位 (int 有 32 位)
            if (n & (1 << i)) {
                ret++;
            }
        }
        return ret;
    }
};
// @lc code=end

