/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
#include <algorithm>
#include <limits.h>
#include <vector>

using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int preValue = 0;
        int maxV = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            preValue = max(preValue + nums[i], nums[i]);
            maxV = max(preValue, maxV);
        }
        return maxV;
    }
};
// @lc code=end

