/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> waySteps(46);
        waySteps[0] = 0;
        waySteps[1] = 1;
        waySteps[2] = 2;

        if (n <=2) {
            return waySteps[n];
        }

        // 第 i 个梯子可以从第 i - 1 或者第 i - 2 个跨上来
        // 所以把前面的方法加起来就好了
        for (int i = 3; i <= n; i++) {
            waySteps[i] = waySteps[i - 1] + waySteps[i - 2];
        }
        return waySteps[n];
    }
};
// @lc code=end

