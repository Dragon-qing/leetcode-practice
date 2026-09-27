/*
 * @Author: Dragon-qing
 * @Date: 2026-09-27
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\1190\solution.cpp
 * @Description: 数组
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1190 lang=cpp
 *
 * [1190] 反转每对括号间的子串
 */

// @lc code=start
class Solution {
public:
    string reverseParentheses(string s) {
        // 预处理建立双向链接
        int n = s.size();
        stack<int> st;
        unordered_map<int ,int>paren;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.emplace(i);
            } else if (s[i] == ')') {
                int a = st.top();
                st.pop();
                paren[a] = i;
                paren[i] = a;
            }
        }

        int step = 1;
        string ans = "";
        for (int i = 0; i < n; i += step) {
            if (s[i] == '(' || s[i] == ')') {
                step = -step;
                i = paren[i];
            } else {
                ans += s[i];
            }
        }

        return ans;
    }
};
// @lc code=end

