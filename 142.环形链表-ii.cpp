/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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

/*
    遇上一题不同的是，这一题需要找到入口的节点
    两个节点相遇后，虚拟一个节点从头出发就好了
*/

#include <iostream>

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // 如果头节点是空，那么
        if (head == nullptr) {
            return nullptr;
        }
        if (head->next == nullptr) {
            return nullptr;
        }
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr) {
            if (fast->next == nullptr) {
                return nullptr;
            }
            // 快指针走两步，慢指针走一步
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) {
                // 一个新的节点从头部出来，然后跟 slow 同步走
                ListNode* tmp = head;
                while (tmp != slow) {
                    tmp = tmp->next;
                    slow = slow->next;
                }
                return tmp;
            }
        }
        return nullptr;
    }
};
// @lc code=end

