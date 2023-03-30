/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        // 直接反过来看
        int lastIndex = s.size() - 1;

        while (s[lastIndex] == ' ') {
            lastIndex--;
        }

        int wordLength = 0;
        while(lastIndex >= 0 && s[lastIndex] != ' ') {
            wordLength++;
            lastIndex--;
        }
        return wordLength;
    }
};
// @lc code=end

