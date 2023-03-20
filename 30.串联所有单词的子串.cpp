/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int wordcount = words.size();
        int wordlen = words[0].size();
        int slen = s.size();

        // i < wordlen -> 移动的范围不超过一个单词
        // i + wordcount * wordlen -> 移动的下标没有超过给定的字符串
        for (int i = 0; i < wordlen && i + wordcount * wordlen <= slen; i++) {
            unordered_map<string, int> differ;
            // 滑动窗口，对给定的字符串按照包含多少个单词进行划分
            for (int j = 0; j < wordcount; j++) {
                ++differ[s.substr(i + j * wordlen, wordlen)];
            }
            // 统计还要出现多少次,
            for (string &word: words) {
                if (--differ[word] == 0) {
                    differ.erase(word);
                }
            }
            // 核心算法在这：以 wordlen 为大小，进行滑动窗口，但是不同的是，start 的开始是以 i
            for (int start = i; start < slen - wordcount * wordlen + 1; start += wordlen) {
                if (start != i) {
                    // 右边的单词滑入
                    string word = s.substr(start + (wordcount - 1) * wordlen, wordlen);
                    if (++differ[word] == 0) {
                        differ.erase(word);
                    }
                    // 左边的单词滑出
                    word = s.substr(start - wordlen, wordlen);
                    if (--differ[word] == 0) {
                        differ.erase(word);
                    }
                }
                if (differ.empty()) {
                    res.emplace_back(start);
                }
            }
        }
        return res;
    }
};
// @lc code=end

