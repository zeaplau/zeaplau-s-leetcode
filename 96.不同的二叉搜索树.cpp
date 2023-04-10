/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start

/*
    G(n): 长度为 n 的序列能够构建的子树数目
    F(i, n): 以 i 为根，序列长度为 n 的不同二叉搜索树
    G(0) 只有一种，就是空指针
    G(1) 也只有一种，单棵树
    G(n) = \sum{F(i, n)} for i \in [2, n]
    F(i, n) = G(i - 1) * G(n - i)
    G(n) = \sum{G(i - 1) * G(n - i)} for i \in [2, n]
*/

#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> G(n + 1, 0);
        G[0] = 1;
        G[1] = 1;

        // 笛卡尔乘积
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                G[i] += G[j - 1] * G[i - j];
            }
        }
        return G[n];
    }
};
// @lc code=end

