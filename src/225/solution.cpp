/*
 * @Author: Dragon-qing
 * @Date: 2026-03-10
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\225\solution.cpp
 * @Description: 队列，栈
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        queue1.push(x);
    }
    
    int pop() {
        int n = queue1.size();
        n -= 1;
        while(n--)
        {
            queue2.push(queue1.front());
            queue1.pop();
        }
        int ans = queue1.front();
        queue1.pop();
        queue1 = queue2;
        while(queue2.size())
        {
            queue2.pop();
        }
        return ans;
    }
    
    int top() {
        return queue1.back();
    }
    
    bool empty() {
        return queue1.empty();
    }
private:
    queue<int> queue1;
    queue<int> queue2;
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

