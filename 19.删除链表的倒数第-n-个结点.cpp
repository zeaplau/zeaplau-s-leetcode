/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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

// the dummy node is important
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode* dummy = new ListNode(0, head);
        ListNode* cur = dummy;
        ListNode* tail = head;
        for (int i = 0; i < n; i++) {
            tail = tail->next;
        }
        while (tail != nullptr) {
            cur = cur->next;
            tail = tail->next;
        }
        cur->next = cur->next->next;
        return dummy->next;
    }
};
// @lc code=end

