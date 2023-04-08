/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start

/*
    这题最大的问题是，如何把 LRU 整个过程整明白，实际上并不难，但是需要细心
    - 将节点移到头部
    - 如果超过了给定容量，移除尾节点
    - 如果有访问到某个节点，那么这个节点要移动到头部
    - 如果新加入了某个节点，先查看这个节点是否在缓存，如果在就更新对应的值并且移动到头部，不在那就将其加入到头部
      需要注意，这个时候还要考虑加入后是否超过容量
*/

#include <unordered_map>

struct DoubleLinkedList {
    int key, value;
    DoubleLinkedList* prev;
    DoubleLinkedList* next;
    DoubleLinkedList(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DoubleLinkedList(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    std::unordered_map<int, DoubleLinkedList*> cache;
    DoubleLinkedList* head;
    DoubleLinkedList* tail;
    int size;
    int capacity;

public:
    LRUCache(int capacity) {
        // 初始化链表属性
        this->capacity = capacity;
        this->size = 0;

        // 初始化链表
        head = new DoubleLinkedList();
        tail = new DoubleLinkedList();
        head->next = tail;
        tail->prev = head;
    }

    void addToHead(DoubleLinkedList* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    // 注意这个移动到头部，可以直接封装两个写好的函数
    void moveToHead(DoubleLinkedList* node) {
        removeNode(node);
        addToHead(node);
    }

    DoubleLinkedList* removeTail() {
        DoubleLinkedList* node = tail->prev;
        removeNode(node);
        return node;
    }

    void removeNode(DoubleLinkedList* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        // 构建一个新的节点，并且将其移动到头部
        DoubleLinkedList* node = cache[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        // 如果在缓存里面没有这个节点
        if (!cache.count(key)) {
            DoubleLinkedList* node = new DoubleLinkedList(key, value);
            // 将节点加入到缓冲中
            cache[key] = node;
            // 因为是本次加入的节点，所以肯定是最近访问过的，直接放到头部
            addToHead(node);
            this->size++;
            // 如果加入了这个节点后，超过了容量
            // 那就将尾巴节点给移出
            if (this->size > this->capacity) {
                DoubleLinkedList* toRemove = removeTail();
                cache.erase(toRemove->key);
                delete toRemove;
                this->size--;
            }
        } else {
            DoubleLinkedList* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

