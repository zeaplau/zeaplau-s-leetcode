/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // 如果头节点指向空，那么肯定没有环
        if (head == nullptr) {
            return false;
        }
        // 如果头节点的下一个指针就指向空，那么也是没有环的
        if (head->next == nullptr) {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            // 两个碰撞在一起了，那么说明肯定存在环
            if (fast == slow) {
                return true;
            }
            // fast 要一下走两步，而 slow 一下只能走一步
            fast = fast->next->next;
            slow = slow->next;
        }
        return false;
    }
};
// @lc code=end

