/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        // 将原来的字符串进行排序，如果为 字母异味词，那排序后的结果肯定是一样的
        for (auto& str: strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            map[sortedStr].emplace_back(str);
        }
        
        vector<vector<string>> ans;
        for (auto it = map.begin(); it != map.end(); it++) {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};
// @lc code=end

