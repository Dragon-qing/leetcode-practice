/*
 * @Author: Dragon-qing
 * @Date: 2026-03-28
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\2573\solution.cpp
 * @Description: 矩阵，动态规划，贪心
 */
#include <bits/stdc++.h>
#include "common.h"
using namespace std;

/*
 * @lc app=leetcode.cn id=2573 lang=cpp
 *
 * [2573] 找出对应 LCP 矩阵的字符串
 */

// @lc code=start
class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        char alternative = 'a';
        string s(n, 0);

        int i = 0; // s[i] 没有填字母
        for (char c = 'a'; c <= 'z'; c++) {
            for (int j = i; j < n; j++) {
                if (lcp[i][j]) { // s[j] == s[i]
                    s[j] = c;
                }
            }
            // 找下一个空位
            while (i < n && s[i]) {
                i++;
            }
            if (i == n) { // 没有空位
                break;
            }
        }

        if (i < n) { // 还有空位
            return "";
        }

        // 根据s计算新lcp矩阵，并比较两者是否相等
        vector<vector<int>> newLcp(n, vector<int>(n));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (s[i] != s[j])
                {
                    newLcp[i][j] = 0;
                }
                else
                {
                    if (i == n - 1 || j == n - 1) // 其中一个串只有一个字符
                    {
                        newLcp[i][j] = 1;
                    }
                    else
                    {
                        newLcp[i][j] = newLcp[i + 1][j + 1] + 1;
                    }
                }
            }
        }
        if (lcp != newLcp)
        {
            return {};
        }
        return s;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<vector<int>> v = Read2DVectorIntFromFile("..\\..\\test\\data.txt");
    cout << s.findTheString(v);
    return 0;
}
