/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    ListNode* findMiddleNode(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        // 两个都要是头节点，但是一个走快点一个走慢点罢了
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseNode(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while (cur != nullptr) {
            // 先记录下一个节点
            ListNode* tmp = cur->next;
            // 指向前面
            cur->next = prev;
            // prev 更新到现在的节点去
            prev = cur;
            // cur 更新到下一个节点去
            cur = tmp;
        }
        return prev;
    }

    void mergeList(ListNode* l1, ListNode* l2) {
        ListNode* l1_tmp;
        ListNode* l2_tmp;

        // l_1 -> l_n -> l_2 -> l_n-1 -> ...
        // 说明两个链表逐步递进就好了
        while (l1 != nullptr && l2 != nullptr) {
            l1_tmp = l1->next;
            l2_tmp = l2->next;

            l1->next = l2;
            l1 = l1_tmp;

            l2->next = l1;
            l2 = l2_tmp;
        }
    }

    void reorderList(ListNode* head) {
        if (head == nullptr) {
            return;
        }
        // 找到中间的节点
        ListNode* mid = findMiddleNode(head);
        ListNode* l1 = head;
        // 后半段的节点
        ListNode* l2 = mid->next;
        // 记得将前后半段的截断
        mid->next = nullptr;
        // 反转
        l2 = reverseNode(l2);
        // 将前半段和后半段进行合并
        mergeList(l1, l2);
    }
};
// @lc code=end

