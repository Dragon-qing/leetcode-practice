#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        m_stackin.push(x);
    }
    
    int pop() {
        if (m_stackout.empty())
        {
            while(!m_stackin.empty())
            {
                int n = m_stackin.top();
                m_stackin.pop();
                m_stackout.push(n);
            }
        }
        int res = m_stackout.top();
        m_stackout.pop();
        return res;
    }
    
    int peek() {
        int n = pop();
        m_stackout.push(n);
        return n;
    }
    
    bool empty() {
        return m_stackin.empty() && m_stackout.empty();
    }
private:
    stack<int> m_stackin;
    stack<int> m_stackout;
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

