/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur_node= dummy;

        ListNode* l1_cur = list1;
        ListNode* l2_cur = list2;

        while (l1_cur != nullptr && l2_cur != nullptr) {
            if (l1_cur->val < l2_cur->val) {
                cur_node->next = l1_cur;
                l1_cur = l1_cur->next;
            }
            else if (l1_cur->val >= l2_cur->val) {
                cur_node->next = l2_cur;
                l2_cur = l2_cur->next;
            }
            cur_node = cur_node->next;
        }
        if (l1_cur == nullptr) {
            cur_node->next = l2_cur;
        }
        if (l2_cur == nullptr) {
            cur_node->next = l1_cur;
        }
        return dummy->next;
    }
};
// @lc code=end

