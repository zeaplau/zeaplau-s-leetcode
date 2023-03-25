/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
#include <vector>

using namespace std;


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int rightMost = 0;
        // dp，使用当前最远的位置和这个位置能够跳到最远的地方比较
        for (int i = 0; i < n; i++) {
            if (i <= rightMost) {
                rightMost = max(rightMost, nums[i] + i);
                // `等于` 说明刚好能够达到
                if (rightMost >= n - 1) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end

