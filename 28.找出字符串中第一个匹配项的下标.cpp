/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int org_strsize = haystack.size();
        int pattern_size = needle.size();
        if (pattern_size == 0) {
            return 0;
        }

        // 设置哨兵
        haystack.insert(haystack.begin(), ' ');
        needle.insert(needle.begin(), ' ');
        vector<int> next(pattern_size + 1);

        // 预处理 next 数组
        for (int i = 2, j = 0; i <= pattern_size; i++) {
            while (j && needle[i] != needle[j + 1]) {
                j = next[j];
            }
            if (needle[i] == needle[j + 1]) {
                j++;
            }
            next[i] = j;
        }

        // 匹配过程
        for (int i = 1, j = 0; i < org_strsize; i++) {
            while (j && haystack[i] != needle[j + 1]) {
                j = next[j];
            }
            if (haystack[i] == needle[j + 1]) {
                j++;
            }
            if (j == pattern_size) {
                return i - pattern_size;
            }
        }
        return -1;
    }
};
// @lc code=end

