/*
 * @Author: Dragon-qing
 * @Date: 2026-04-07
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\155\solution.cpp
 * @Description: 最小栈
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
/* class MinStack {
public:
    MinStack() {
    }
    
    void push(int val) {
        m_sOriginSt.push(val);
        if (m_sMinSt.empty())
        {
            m_sMinSt.push(val);
        }
        else
        {
            stack<int> tmpSt;
            while (!m_sMinSt.empty() && m_sMinSt.top() < val)
            {
                tmpSt.push(m_sMinSt.top());
                m_sMinSt.pop();
            }
            m_sMinSt.push(val);
            while(!tmpSt.empty())
            {
                m_sMinSt.push(tmpSt.top());
                tmpSt.pop();
            }
        }

    }
    
    void pop() {
        if (m_sOriginSt.empty())
        {
            return;
        }
        int topElem = m_sOriginSt.top();
        m_sOriginSt.pop();
        stack<int> tmpSt;
        while (!m_sMinSt.empty() && m_sMinSt.top() < topElem)
        {
            tmpSt.push(m_sMinSt.top());
            m_sMinSt.pop();
        }
        m_sMinSt.pop();
        while(!tmpSt.empty())
        {
            m_sMinSt.push(tmpSt.top());
            tmpSt.pop();
        }
    }
    
    int top() {
        return m_sOriginSt.top();
    }
    
    int getMin() {
        return m_sMinSt.top();
    }
private:
    stack<int> m_sOriginSt;
    stack<int> m_sMinSt;
}; */

// 优化，另一个栈只用压入当前最小的值即可
class MinStack {
public:
    MinStack() {
    }
    
    void push(int val) {
        m_stOrigin.push(val);
        if (m_stMin.empty())
        {
            m_stMin.push(val);
        }
        else
        {
            m_stMin.push(min(val, m_stMin.top()));
        }

    }
    
    void pop() {
        if (m_stOrigin.empty())
        {
            return;
        }
        
        m_stOrigin.pop();
        m_stMin.pop();
    }
    
    int top() {
        return m_stOrigin.top();
    }
    
    int getMin() {
        return m_stMin.top();
    }
private:
    stack<int> m_stOrigin;
    stack<int> m_stMin;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

int main()
{
    MinStack st;
    st.push(-2);
    st.push(0);
    st.push(-3);
    cout << st.getMin();
    st.pop();
    cout << st.top();
    cout << st.getMin();
    return 0;
}
