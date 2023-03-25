/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N 皇后 II
 */

// @lc code=start
#include <unordered_set>

using namespace std;

class Solution {
public:
    int backtrace(int n, int row, unordered_set<int> &col, unordered_set<int> &dg, unordered_set<int> &udg) {
        // backtrace 条件满足
        if (row == n) {
            return 1;
        } else {
            int count = 0;
            for (int i = 0; i < n; i++) {
                // 如果发现这个位置已经占了一个皇后
                if (col.find(i) != col.end()) {
                    continue;
                }
                // 左下 / 左上
                int dgPos = row - i;
                if (dg.find(dgPos) != dg.end()) {
                    continue;
                }
                // 右上 / 右下
                int udgPos = row + i;
                if (udg.find(udgPos) != udg.end()) {
                    continue;
                }

                col.insert(i);
                dg.insert(dgPos);
                udg.insert(udgPos);
                count += backtrace(n, row + 1, col, dg, udg);
                col.erase(i);
                dg.erase(dgPos);
                udg.erase(udgPos);
            }
        return count;
        }
    }

    int totalNQueens(int n) {
        unordered_set<int> col, dg, udg;
        return backtrace(n, 0, col, dg, udg);
    }
};
// @lc code=end

