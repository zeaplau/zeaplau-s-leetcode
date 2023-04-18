/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
/*
    贪心算法，实际上用一个坐标图来理解更好
*/


#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int start_idx = 0;
        int sum = 0;
        int min_sum = 0;

        for (int i = 0; i < n; i++) {
            // 攒汽
            sum += gas[i] - cost[i];
            // 如果这个时候攒的比之前的最小值还要小（说明从这个节点开始不足够消耗）
            // ，那么说明以这个地方为起点比较合适
            if (sum < min_sum) {
                min_sum = sum;
                // 往下一站进发
                start_idx = i + 1;
            }
        }

        // 全程下来都不够气用，无法环游
        if (sum < 0) {
            return -1;
        }
        // 如果 n - 1 前面，还是不足够小号，那么从最后一站
        // 开始
        return start_idx == n ? 0 : start_idx;
    }
};
// @lc code=end

