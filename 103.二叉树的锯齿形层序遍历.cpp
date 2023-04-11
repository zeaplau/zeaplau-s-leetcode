/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
#include <queue>

// struct TreeNode {
//      int val;
//      TreeNode *left;
//      TreeNode *right;
//      TreeNode() : val(0), left(nullptr), right(nullptr) {}
//      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  };

using namespace std;

class Solution {
public:
    queue<TreeNode*> nodes;
    vector<vector<int>> res;

    void bfs(TreeNode* root, int isReverse) {
        while (!this->nodes.empty()) {
            // 当前队列的长度
            int size = this->nodes.size();
            // 用来保存当前层级的值
            deque<int> levelRes;
            for (int i = 0; i < size; i++) {
                auto cur = nodes.front();
                nodes.pop();
                // 头插入就是反序，尾插入就是正序，这个过程要好好想想
                if (isReverse) {
                    levelRes.push_front(cur->val);
                } else {
                    levelRes.push_back(cur->val);
                }
                // 将下面的加入到队列里面
                if (cur->left) {
                    nodes.push(cur->left);
                }
                if (cur->right) {
                    nodes.push(cur->right);
                }
            }
            res.emplace_back(vector<int>{levelRes
            .begin(), levelRes.end()});
            // 改变方向
            if (isReverse) {
                isReverse = false;
            } else {
                isReverse = true;
            }
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        this->nodes.push(root);
        bfs(root, 0);
        return this->res;
    }
};
// @lc code=end

