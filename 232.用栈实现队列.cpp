/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
#include <stack>

using namespace std;

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;

    MyQueue() {

    }
    
    void s12s2() {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }

    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int ret;
        // 如果 s2 不是空的
        // 那么直接从 s2 弹出
        if (s2.empty()) {
            this->s12s2();
        }
        ret = s2.top();
        s2.pop();
        return ret;
    }
    
    int peek() {
        if (s2.empty()) {
            this->s12s2();
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

