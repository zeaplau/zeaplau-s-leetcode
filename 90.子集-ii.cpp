/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
    做这题的时候犯了个错误，就是把重复的先跳过了
    应该先把第一个（第一个肯定没有重复）丢进去，再判断后面的是否重复
*/
class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    
    void dfs(vector<int>& nums, int cur) {
        // 到达最后面的一位
        if (cur == nums.size()) {
            res.push_back(tmp);
            return;
        }

        // 添加当前位置
        tmp.push_back(nums[cur]);
        dfs(nums, cur + 1);

        // 不考虑当前位置
        // 那就得把之前加入的 pop 出来
        tmp.pop_back();
        
        // ※ 还有这里需要着重思考一下
        // 如果遇到了相同的数字，那就跳过
        // 这里有一个比较深层的逻辑
        // 遍历 [1, 2, 2, 2, 3] 的时候，[1, 2, 2, 3] 这样的情况肯定遍历过（因为上面添加当前位置那里）
        // 实际上就是上述的添加当前位置的时候，已经把重复的数字已经根据次数枚举完了
        while (cur < nums.size() - 1 && nums[cur] == nums[cur + 1]) {
            cur += 1;
        }

        dfs(nums, cur + 1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return res;
    }
};
// @lc code=end

