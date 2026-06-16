/*
 * @Author: Dragon-qing
 * @Date: 2026-06-16
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3612\solution.cpp
 * @Description: 字符串，模拟
 */
#include <bits/stdc++.h>
#include "fmt/base.h"
using namespace std;

/*
 * @lc app=leetcode.cn id=3612 lang=cpp
 *
 * [3612] 用特殊操作处理字符串 I
 */

// @lc code=start
class Solution {
public:
    string processStr(string s) {
        m_result = "";
        for (char c : s)
        {
            OptProcess(c);
        }

        return m_result;
    }

    void OptProcess(char c)
    {
        if (c == '#')
        {
            m_result += m_result;
        } 
        else if (c == '*')
        {
            if (!m_result.empty())
            {
                m_result.pop_back();
            }
        }
        else if (c == '%')
        {
            reverse(m_result.begin(), m_result.end());
        }
        else
        {
            m_result += c;
        }
    }
private:
    string m_result;
};
// @lc code=end

int main()
{
    Solution s;
    string str = "a#b%*";
    fmt::println("res={}", s.processStr(str));
    return 0;
}

