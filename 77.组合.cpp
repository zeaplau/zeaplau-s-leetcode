/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
#include <stdlib.h>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return res;
    }
    void dfs(int cur, int n, int k) {
        // pruning if the rest length and the contained length smaller than k
        if (path.size() + (n - cur + 1) < k) {
            return;
        }
        // Record legal answer
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
        // Consider current position
        path.push_back(cur);
        dfs(cur + 1, n, k);
        // Recover
        path.pop_back();
        // Not consider current position
        dfs(cur + 1, n, k);
    }
};
// @lc code=end

