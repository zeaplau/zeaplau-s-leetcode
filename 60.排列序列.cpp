/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 排列序列
 */

// @lc code=start
// not debug yet
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> res;
    void dfs(int index, int end, string& path) {
        // 如果交换到最后，那么就将结果放进去
        if (index == end) {
            res.emplace_back(path);
            return;
        }
        for (int i = index; i < end; i++) {
            swap(path[i], path[index]);
            dfs(index + 1, end, path);
            swap(path[i], path[index]);
        }
    }

    string getPermutation(int n, int k) {
        string s = "";
        string path = "";
        for (int i = 0; i < n; i++) {
            s += "i";
        }
        dfs(0, s.size(), path);
        sort(res.begin(), res.end());
        return res[k - 1];
    }
};
// @lc code=end

