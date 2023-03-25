/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    vector<bool> col, dg, udg;
    vector<string> g;
    int bound;

    void NQueen(int u, vector<vector<string>> &res) {
        int n = this->bound;
        if (u == n) {
            res.push_back(g);
            return;
        }
        
        // 条件是两个皇后不能在同一行 通过一列 同一对角线
        for (int i = 0; i < n; i++) {
            if (!col[i] && !dg[u + i] && !udg[n - u + i]) {
                // 满足条件，那么这个地方可以放入一个皇后
                g[u][i] = 'Q';
                col[i] = true;
                dg[u + i] = true;
                udg[n - u + i] = true;
                NQueen(u + 1, res);
                // 回到原来的样子
                col[i] = false;
                dg[u + i] = false;
                udg[n - u + i] = false;
                g[u][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        this->bound = n;
        this->col = vector<bool>(n, false);
        // 两个方向上的对角线, 分别是左上到右下以及右上到左下
        // 这里为什么是两倍的原因是，有可能直接从两个角角对起来，这个时候
        // 下标数就超过了整个版面
        this->dg = vector<bool>(2 * n, false);
        this->udg = vector<bool>(2 * n, false);

        string tmp = "";
        for (int i = 0; i < n; i++) {
            tmp += ".";
        }
        this->g = vector<string>(n, tmp);
        NQueen(0, res);
        return res;
    }
};
// @lc code=end

