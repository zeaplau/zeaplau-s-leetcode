/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
/*
    第 i 天的最低点
        dp[i] = min(dp[i - 1], prices[i])
*/
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_reward = 0;
        vector<int> dp(prices.size());
        dp[0] = prices[0];

        for (int i = 1; i < prices.size(); i++) {
            dp[i] = min(dp[i - 1], prices[i]);
            // 用当前的价格减去最低点
            max_reward = max(prices[i] - dp[i], max_reward);
        }
        return max_reward;
    }
};
// @lc code=end

