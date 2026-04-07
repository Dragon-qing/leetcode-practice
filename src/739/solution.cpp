/*
 * @Author: Dragon-qing
 * @Date: 2026-04-07
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\739\solution.cpp
 * @Description: 每日温度， 栈
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> st; // 保证栈内元素递减
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && temperatures[st.top()] < temperatures[i])
            {
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }

        return res;
    }
};
// @lc code=end

