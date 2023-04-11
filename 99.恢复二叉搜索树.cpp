/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
    用递归比较烧脑子
    实际上用来保存两个节点，因为如果进行了交换，降序对
    肯定出现两个
    这个时候需要的是找到第一个降序对，确定第一个降序的节点（就是 pred），这个时候需要交换的元素在第一个位置
    然后找到第二个降序对，第二个降序对需要交换的元素在第二个位置
*/
#include <iostream>

using namespace std;

class Solution {
public:
    TreeNode* pred = nullptr;
    TreeNode* tar1 = nullptr;
    TreeNode* tar2 = nullptr;

    // 中序遍历
    void dfs(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        // 往左边走
        dfs(root->left);
        // 如果遇到了上一个值和现在的大小关系不符合二叉搜索树
        if (this->pred != nullptr) {
            if (this->pred->val >= root->val) {
                // 这里确定第一个目标
                if (this->tar1 == nullptr) {
                    this->tar1 = pred;
                    this->tar2 = root;
                } else {
                    // 一直更新，知道最后一个降序对
                    this->tar2 = root;
                    return;
                }
            }
        }
        this->pred = root;
        dfs(root->right);
    }

    void recoverTree(TreeNode* root) {
        dfs(root);
        swap(this->tar1->val, this->tar2->val);
    }
};
// @lc code=end

