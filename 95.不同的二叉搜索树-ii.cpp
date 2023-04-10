/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 */

// @lc code=start
/**
 * Definition for a binary tree node.

 */

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

/*
    分治加上回溯的思想，二叉搜索树左边肯定比右边小，所以可以用一个
    idx 指定哪一个数字作为 root，然后生成其相应的左右子树，最后
    遍历所有可能生成的左右子树，将其和根拼接起来
*/
#include <vector>

using namespace std;

class Solution {
public:
    vector<TreeNode*> generate(int start, int end) {
        // 这个时候子树全部遍历完了
        if (start > end) {
            return {nullptr};
        }
        vector<TreeNode*> tmpTrees;
        for (int i = start; i <= end; i++) {
            // 遍历左边的子树
            vector<TreeNode*> leftTrees = generate(start, i - 1);
            // 遍历右边的子树
            vector<TreeNode*> rightTrees = generate(i + 1, end);

            // 将两边子树进行拼接
            for (auto &l : leftTrees) {
                for (auto &r : rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    tmpTrees.emplace_back(root);
                }
            }
        }
        return tmpTrees;
    }
    vector<TreeNode*> generateTrees(int n) {
        if (!n) {
            return {};
        } else {
            return generate(1, n);
        }
    }
};
// @lc code=end

