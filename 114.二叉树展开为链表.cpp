/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    vector<TreeNode*> nodes;

    void inorder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        nodes.push_back(root);
        inorder(root->left);
        inorder(root->right);
    }

    void flatten(TreeNode* root) {
        inorder(root);
        TreeNode* prev = root;
        TreeNode* latent = nullptr;
        for (auto& node: nodes) {
            if (node == prev) {
                continue;
            }
            latent = node;
            prev->right = latent;
            prev->left = nullptr;
            prev = latent;
        }
    }
};
// @lc code=end

