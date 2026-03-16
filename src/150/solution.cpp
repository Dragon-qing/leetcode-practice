/*
 * @Author: Dragon-qing
 * @Date: 2026-03-16
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\150\solution.cpp
 * @Description: 栈
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st{};
        for (auto s : tokens)
        {
            if (s == "+" || s == "-" || s == "*" || s == "/")
            {
                long long y = st.top();
                st.pop();
                long long x = st.top();
                st.pop();

                if (s == "+") st.emplace(x + y);
                if (s == "-") st.emplace(x - y);
                if (s == "*") st.emplace(x * y);
                if (s == "/") st.emplace(x / y);
            }
            else
            {
                st.emplace(stoll(s));
            }
        }
        
        return st.top();
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<string> v = {
        "4","13","5","/","+"
    };
    s.evalRPN(v);
    return 0;
}