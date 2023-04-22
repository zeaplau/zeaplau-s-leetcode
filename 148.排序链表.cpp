/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> sorted_values;
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* cur = head;

        // 全部遍历出来
        while (cur) {
            sorted_values.push_back(cur->val);
            cur = cur->next;
        }
        
        // 将遍历出来的值进行排序，排序后再拿出来构建新的链表
        sort(sorted_values.begin(), sorted_values.end());
        
        // 头节点
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;
        // 开始遍历并且新建一个链表
        for (int i = 0; i < (int)this->sorted_values.size(); i++) {
            ListNode* new_node = new ListNode(this->sorted_values[i]);
            prev->next = new_node;
            prev = new_node;
        }
        return dummy->next;
    }
};

class Solution2 {
public:
    ListNode* sortList(ListNode* head, ListNode* tail) {
        /*
            一直分割，分割得只剩下两个节点
        */

        // 如果只有一个或者两个节点，就说明该滚回去了
        if (head == nullptr) {
            return head;
        }
        if (head->next == nullptr) {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        // 用快慢指针找到中间节点
        while (fast != tail) {
            slow = slow->next;
            fast = fast->next;
            if (fast->next != nullptr) {
                fast = fast->next;
            }
        }
        ListNode* mid = slow;
        // 继续分
        return mergeList(sortList(head, mid), sortList(mid, tail));
    }

    ListNode* mergeList(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* tmp = dummy;
        ListNode* head1 = l1;
        ListNode* head2 = l2;

        // 简单的合并
        // 需要注意的是，这里的合并需要推广情况到上面几层去
        while (head1 != nullptr && head2 != nullptr) {
            if (head1->val <= head2->val) {
                tmp->next = head1;
                head1 = head1->next;
            } else {
                tmp->next = head2;
                head2 = head2->next;
            }
            tmp = tmp->next;
        }
        if (head1 == nullptr) {
            tmp->next = head2;
        }
        if (head2 == nullptr) {
            tmp->next = head1;
        }
        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        return sortList(head, nullptr);
    }
};
// @lc code=end

