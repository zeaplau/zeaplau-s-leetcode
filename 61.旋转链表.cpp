/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
        // 如果移动位置为 0 个 / 传入的节点是空的 / 传入的节点只有一个
        if (k == 0 || head == nullptr || head->next == nullptr) {
            return head;
        } 

        // 表的长度
        ListNode* fast = head;
        int listLen = 1;

        // 记录这个链表的长度
        while (fast->next != nullptr) {
            listLen++;
            fast = fast->next;
        }
        
        int shift = listLen - k % listLen;
        // 如果 shift 了整个链表，那就是没变化
        if (shift == listLen) {
            return head;
        }
        // 这个时候偏移的下一个节点就是头，这一步就是找到新的链表头
        fast->next = head;
        while (shift) {
            fast = fast->next;
            shift -= 1;
        }
        ListNode *res = fast->next;
        fast->next = nullptr;
        return res;
    }
};
// @lc code=end

