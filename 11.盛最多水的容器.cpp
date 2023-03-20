/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int head = 0;
        int tail = n - 1;
        int ans = 0;
        while (head < tail) {
            if (height[tail] < height[head]) {
                ans = max(ans, (tail - head) * height[tail]);
                tail--;
            } else {
                ans = max(ans, (tail - head) * height[head]);
                head++;
            }
        }
        return ans;
    }
};
// @lc code=end

