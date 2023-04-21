/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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

    void postorder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        res.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return res;
        }
        postorder(root);
        return this->res;
    }
};
// @lc code=end

