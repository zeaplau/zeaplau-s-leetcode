/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* next = head->next;
        ListNode* prev_next = head;
        while (next != nullptr) {
            ListNode* prev = dummy;
            ListNode* cursor = head;

            // 如果 cursor 的值比 next 的值要小，同时 cursor 没有
            // 到达 next 这个点，那就继续往前移动
            while (cursor->val <= next->val && cursor != next) {
                prev_next = prev_next->next;
                prev = prev->next;
                cursor = cursor->next;
            }

            // 如果 cursor 移动到了 next 的地方
            // 说明 next 本该在这个位置
            // 那么 prev 和 cursor 归位，prev_next 和 next 移动到下一个位置去
            // 结束本轮
            if (cursor == next) {
                prev = dummy;
                cursor = head;
                prev_next = prev_next->next;
                next = next->next;
                continue;
            }

            // 如果没有遇到，那么说明 cursor 停下来的地方值要比 next 的值大
            // 这个时候 next 作为比较小的值，要插入到 cursor 的前面去
            prev_next->next = next->next;
            prev->next = next;
            next->next = cursor;

            // 移动到下一个位置去
            prev_next = prev_next->next;
            next = next->next;
        }
        // 返回头节点
        return dummy->next;
    }
};
// @lc code=end

