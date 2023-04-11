/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
    这题稍有不同的是，需要将头节点单独摘出来处理
    其他的就递归处理好了
*/

class Solution {
public:
    bool dfs(TreeNode* left, TreeNode* right) {
        // 两者都是空
        if (left == nullptr && right == nullptr) {
            return true;
        }
        // 其中一个是空，另一个不是
        if (left == nullptr || right == nullptr) {
            return false;
        }
        // 如果这两个的值不同，那肯定不是空
        if (left->val != right->val) {
            return false;
        }
        // 左边的左边和右边的右边对比，左边的右边和右边的左边对比
        return dfs(left->left, right->right) && dfs(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        // 如果根是空的，那么直接是对称
        if (root == nullptr) {
            return true;
        }
        return dfs(root->left, root->right);
    }
};
// @lc code=end

