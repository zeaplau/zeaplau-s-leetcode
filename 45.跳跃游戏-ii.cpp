/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        // 能跳跃到的最远距离
        int maxDistance = 0;
        // 跳跃的次数
        int step = 0;
        // 上一次能跳跃到的最远距离
        int end = 0;
        // 在访问最后一个元素之前，边界肯定是大于等于最后一个位置的，所以不用进入到最后一个元素
        for (int i = 0; i < nums.size() - 1; i++) {
            maxDistance = max(maxDistance, i + nums[i]);
            if (i == end) {
                end = maxDistance;
                step++;
            }
        }
        return step;
    }
};
// @lc code=end

