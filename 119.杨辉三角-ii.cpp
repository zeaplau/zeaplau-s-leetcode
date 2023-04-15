/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
/*
    Roll the first layer to the previous first.
*/
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // prev layer, cur layer
        vector<int> prev, now;
        for (int i = 0; i <= rowIndex; i++) {
            now.resize(i + 1);
            now[0] = 1;
            now[i] = 1;
            // 当 i >= 1 的时候才会开始
            for (int j = 1; j < i; j++) {
                now[j] = prev[j - 1] + prev[j];
            }
            prev = now;
        }
        return prev;
    }
};
// @lc code=end

