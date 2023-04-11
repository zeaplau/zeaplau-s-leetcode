/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
#include <limits.h>
class Solution {
public:
    bool inorder(TreeNode* root, long long lower, long long upper) {
        // 如果传入的节点是空节点，那肯定是
        // 二叉搜索树
        if (root == nullptr) {
            return true;
        }
        // 如果不符合要求，那就寄，这里有两个要求
        // 直接判断这个 val 是不是在区间外
        if (root->val <= lower || root->val >= upper) {
            return false;
        }
        // 这个地方比较难懂，实际上可以参考二分搜索
        // 往左边走，实际上改变的是上界
        // 往右边走，实际上改变的是下界
        return inorder(root->left, lower, root->val) && inorder(root->right, root->val, upper);
    }

    bool isValidBST(TreeNode* root) {
        return inorder(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }
};
// @lc code=end

