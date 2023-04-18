/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

#include <unordered_map>
#include <vector>

using namespace std;

// class Node {
// public:
//     int val;
//     vector<Node*> neighbors;
//     Node() {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val) {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };

/*
    这里还可以扩展成其他形式，比如遍历一个图，但是各种连同
    采用 BFS 的方法也可以
*/

class Solution {
public:
    unordered_map<Node*, Node*> visited;
    Node* cloneGraph(Node* node) {
        // 如果这个节点是空的
        if (node == nullptr) {
            return nullptr;
        }

        // 如果这个节点访问过
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }

        // 克隆这个节点，并且把这个 clone 的节点和原来的节点对应起来
        // 并且记录这个节点（如果这个节点访问过）
        Node* cloneNode = new Node(node->val);
        visited[node] = cloneNode;

        for (auto &node : node->neighbors) {
            // 这里递归很漂亮，直接从邻居节点 dfs 过去
            cloneNode->neighbors.emplace_back(cloneGraph(node));
        }
        return cloneNode;
    }
};
// @lc code=end

