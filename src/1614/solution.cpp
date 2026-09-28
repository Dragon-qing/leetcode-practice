/*
 * @Author: Dragon-qing
 * @Date: 2026-09-28
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\1614\solution.cpp
 * @Description: 栈
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1614 lang=cpp
 *
 * [1614] 括号的最大嵌套深度
 */

// @lc code=start
class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        stack<int> st;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
                ans = max(ans, (int)st.size());
            } else if (s[i] == ')') {
                st.pop();
            }
        }
        return ans;
    }
};
// @lc code=end

