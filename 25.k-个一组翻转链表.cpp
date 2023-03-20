/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
#include <utility>

using namespace std;

class Solution {
public:
    pair<ListNode*, ListNode*> reverse(ListNode* start, ListNode* end) {
        // 这里后续也要反转，所以 prev = end->next
        ListNode* prev = end->next;
        ListNode* cur = start;
        while (prev != end) {
            // 这里出现了反转
            ListNode* next = cur->next;
            cur->next = prev;
            // 因为这里已经反转了，cur 会变成之前的节点，所以直接将 prev 设置为 cur
            prev = cur;
            cur = next;
        }
        return {end, start};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        while (head) {
            ListNode* end = prev;
            // 查看剩余的链表是否长于 k 个
            for (int i = 0; i < k; i++) {
                end = end->next;
                if (end == nullptr) {
                    return dummy->next;
                }
            }
            ListNode* next = end->next;
            pair<ListNode*, ListNode*> result = reverse(head, end);

            head = result.first;
            end = result.second;
            prev->next = head;
            end->next = next;
            prev = end;
            head = end->next;
        }
        return dummy->next;
    }
};
// @lc code=end

