/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        // dummy head
        ListNode* smallHead = new ListNode();
        ListNode* largeHead = new ListNode();
        // current position in list to merge
        ListNode* smallCur = smallHead;
        ListNode* largeCur = largeHead;

        // current position in current list
        ListNode* cur = head;

        while (cur != nullptr) {
            if (cur->val < x) {
                // add to small list
                smallCur->next = cur;
                smallCur = smallCur->next;
            }
            if (cur->val >= x) {
                // add to large list
                largeCur->next = cur;
                largeCur = largeCur->next;
            }
            cur = cur->next;
        }
        // merge list
        // the last node of large list is nullptr
        largeCur->next = nullptr;
        // the small list links to the large list
        smallCur->next = largeHead->next;
        return smallHead->next;
    }
};
// @lc code=end

