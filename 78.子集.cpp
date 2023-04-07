/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;

    void dfs(vector<int> &nums, int cur) {
        if (cur == nums.size()) {
            this->res.push_back(this->tmp);
            return;
        }
        // 如果我们考虑这个位置，那就将这个位置加入
        this->tmp.push_back(nums[cur]);
        dfs(nums, cur + 1);

        // 如果我们不考虑这个位置
        // 因为先前我们把这个位置加进去了
        // 所以还要 pop 出来
        this->tmp.pop_back();
        dfs(nums, cur + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return this->res;
    }
};
// @lc code=end

