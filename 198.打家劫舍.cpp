/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start

/*
    思路：
     - 看到这种能够化为子问题的，首先考虑用 dp
     - 首先考虑它不能偷两个相邻的房子，那么可以肯定会以 '2' 作为一个间隔，这里是入手 dp 公式的关键
     - 考虑前 i 个最大的，可以发现要不
        1. 偷当前的，不偷前面的，偷前面的前面的
        2. 不偷当前的
     - 于是可以列得公式： dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1])
    因为 dp 多了一个 dp[0] = 0，就是不偷第一个这种情况，所以 nums 对应当前房子是 i - 1
*/

#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, 0);
        dp[1] = nums[0];
        for (int i = 2; i < dp.size(); i++) {
            dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
        }
        return dp[(int)nums.size()];
    }
};
// @lc code=end

