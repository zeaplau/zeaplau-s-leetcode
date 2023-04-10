/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> res;

    void inorder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        if (root->left != nullptr) {
            inorder(root->left);
        }
        res.push_back(root->val);
        if (root->right != nullptr) {
            inorder(root->right);
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return this->res;
    }
};
// @lc code=end

