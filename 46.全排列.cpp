/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int>& output, int first, int len) {
        if (first == len) {
            res.emplace_back(output);
            return;
        }
        // 交换第 first 个 字母
        for (int i = first; i < len; i++) {
            // 进行交换
            swap(output[i], output[first]);
            // 交换后进行 dfs
            dfs(res, output, first + 1, len);
            // 交换回去
            swap(output[first], output[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        dfs(res, nums, 0, (int)nums.size());
        return res;
    }
};
// @lc code=end

