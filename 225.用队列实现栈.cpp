/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
#include <queue>

using namespace std;

class MyStack {
public:
    queue<int> mq1;
    queue<int> mq2;

    MyStack() {}
    
    void push(int x) {
        mq1.push(x);
    }
    
    // 模拟后进先出
    int pop() {
        int size = mq1.size();
        while (size > 1) {
            int tmp = mq1.front();
            mq2.push(tmp);
            mq1.pop();
            size--;
        }
        int result = mq1.front();
        mq1.pop();
        while (!mq2.empty()) {
            int tmp = mq2.front();
            mq1.push(tmp);
            mq2.pop();
        }
        return result;
    }
    
    // top 的话都是最后面的一个元素，用脑子模拟一下
    // queue: [1, 2], stack: [2, 1]
    int top() {
        return mq1.back();
    }
    
    bool empty() {
        return mq1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

