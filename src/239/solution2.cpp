/*
 * @Author: Dragon-qing
 * @Date: 2026-03-17
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\239\solution2.cpp
 * @Description: 双向队列
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue q;
        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            q.Push(nums[i]);
        }
        res.push_back(q.Front());
        for (int i = k; i < nums.size(); i++)
        {
            q.Push(nums[i]);
            q.Pop(nums[i - k]);
            res.push_back(q.Front());
        }
        return res;
    }
private:
    class MyQueue{
    public:
        MyQueue(){}
        void Pop(int value)
        {
            if (!m_q.empty() && m_q.front() == value)
            {
                m_q.pop_front();
            }
        }
        void Push(int value)
        {
            while (!m_q.empty() && m_q.back() < value)
            {
                m_q.pop_back();
            }
            m_q.push_back(value);
        }
        int Front()
        {
            if (m_q.empty())
            {
                return INT32_MIN;
            }
            return m_q.front();
        }
    private:
        deque<int> m_q;
    };
};