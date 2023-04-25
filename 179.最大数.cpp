/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> vs;
        // 全部加进去，加入到里面后对这个容器进行排序
        for (auto x : nums) {
            vs.push_back(to_string(x));
        }
        // 保证前面的大于后面的
        sort(vs.begin(), vs.end(), [](const auto& A, const auto& B) {
            return A + B > B + A;
        });
        string ans;
        for (const auto& val : vs) {
            ans += val;
        }
        // 如果第一个就是 0，说明是直接寄了，没有任何数
        return ans[0] == '0' ? "0" : ans;
    }
};
// @lc code=end

