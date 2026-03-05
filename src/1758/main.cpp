/*
 * @Author: Dragon-qing
 * @Date: 2026-03-05
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\1758\main.cpp
 * @Description: 字符串
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        char pre1 = '\0';
        char pre2 = s[0];
        int ans1 = 0;   // 默认第一个位置不用变
        int ans2 = 0;   // 第一个位置需要变
        for (char c : s)
        {
            if (c == pre1)
            {
                ans1 += 1;
                pre1 = (c - '0' + 1) % 2 + '0';
            }
            else
            {
                pre1 = c;
            }

            if (c == pre2)
            {
                ans2 += 1;
                pre2 = (c - '0' + 1) % 2 + '0';
            }
            else
            {
                pre2 = c;
            }
        }

        return min(ans1, ans2);
    }
};

int main()
{
    return 0;
}