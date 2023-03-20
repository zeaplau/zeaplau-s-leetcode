/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* tmp = dummy; // 多用一个 tmp 来解决的 dummy 移动的问题
        while (tmp->next != nullptr && tmp->next->next != nullptr) {
            ListNode* front = tmp->next;
            ListNode* tail = tmp->next->next;
            tmp->next = tail;
            front->next = tail->next;
            tail->next = front;
            tmp = front;
        }
        return dummy->next;
    }
};
// @lc code=end

