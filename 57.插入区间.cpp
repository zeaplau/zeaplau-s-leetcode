/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size();
        int cur = 0;
        // 这个时候考虑的是，集合里面的有些区间，它的右边界还没有给定区间的
        // 左边界大，这个时候将他们放到候选答案里面去
        while (cur < n && intervals[cur][1] < newInterval[0]) {
            res.push_back(intervals[cur++]);
        }
        // 跟某一个区间存在交叠
        // 这个时候查看这个区间和给定的区间左右大小
        while (cur < n && intervals[cur][0] <= newInterval[1]) {
            // 取比较小的那个
            newInterval[0] = min(newInterval[0], intervals[cur][0]);
            // 取比较大的那个
            newInterval[1] = max(newInterval[1], intervals[cur][1]);
            ++cur;
        }
        res.push_back(newInterval);
        while (cur < n) {
            res.push_back(intervals[cur++]);
        }
        return res;
    }
};
// @lc code=end

