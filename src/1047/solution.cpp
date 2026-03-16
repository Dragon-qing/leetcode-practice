/*
 * @Author: Dragon-qing
 * @Date: 2026-03-16
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\1047\solution.cpp
 * @Description: 栈，字符串
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        deque<char> dq;
        for (char c : s)
        {
            if (dq.empty())
            {
                dq.push_back(c);
                continue;
            }

            if (dq.back() == c)
            {
                dq.pop_back();
            }
            else
            {
                dq.push_back(c);
            }
        }
        string res{};
        while (!dq.empty())
        {
            res.push_back(dq.front());
            dq.pop_front();
        }
        return res;
    }
};
// @lc code=end

