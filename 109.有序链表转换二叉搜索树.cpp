/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    跟 108 的思路反过来就好了
*/
class Solution {
public:
    TreeNode* dfs(ListNode* left, ListNode* right) {
        // 如果左指针和右指针指到同一个东西
        // 那么就说明到头了
        if (left == right) {
            return nullptr;
        }
        ListNode* fast = left;
        ListNode* slow = left;

        // 获取中间的节点，就是 fast 节点还没有碰到末尾节点
        while (fast != right && fast->next != right) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // 将中间的节点作为根节点
        TreeNode* root = new TreeNode(slow->val);
        // 分别从左右区间找中间节点作为新的根节点
        root->left = dfs(left, slow);
        root->right = dfs(slow->next, right);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        // 这里的 right 要注意，因为链表末尾一定是空指针
        return dfs(head, nullptr);
    }
};
// @lc code=end

