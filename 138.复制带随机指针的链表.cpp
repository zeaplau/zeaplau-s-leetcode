/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

/*
    使用哈希表对已经复制的节点进行记录，如果没有记录到，说明这个节点是新的
    使用 dfs 的方法对整个链表进行复制
*/

#include <unordered_map>

using namespace std;

// class Node {
// public:
//     int val;
//     Node* next;
//     Node* random;
    
//     Node(int _val) {
//         val = _val;
//         next = NULL;
//         random = NULL;
//     }
// };

class Solution {
public:
    unordered_map<Node*, Node*> node_created;

    Node* copyRandomList(Node* head) {
        // 如果接下来的节点是空的
        if (head == nullptr) {
            return nullptr;
        }

        // 如果容器存在给定的值，那么返回 1，不然返回 0
        if (!node_created.count(head)) {
            Node* cloned = new Node(head->val);
            node_created[head] = cloned;
            cloned->next = copyRandomList(head->next);
            cloned->random = copyRandomList(head->random);
        }
        return node_created[head];
    }
};
// @lc code=end

