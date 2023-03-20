/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start

#include <stack>
#include <unordered_map>
#include <string>

class Solution {
public:
    std::stack<char> bracket_stack;
    std::unordered_map<char, char> pairs = {
        {')', '('}, {'}', '{'}, {']', '['},
    };

    bool isValid(string s) {
        for (auto c: s) {
            // get right bracket
            if (pairs.count(c)) {
                if (bracket_stack.empty() || bracket_stack.top() != pairs[c]) {
                    return false;
                }
                bracket_stack.pop();
            } else {
                bracket_stack.push(c);
            }
        }
        return bracket_stack.empty();
    }
};
// @lc code=end

