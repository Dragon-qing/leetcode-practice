/*
 * @Author: Dragon-qing
 * @Date: 2026-03-06
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\541\main.cpp
 * @Description: 字符串
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for (int i = 0; i < n; i += 2 * k)
        {
            if (i + k > n)
            {
                reverse(s.begin() + i, s.end());
            }
            else if (i + k <= n)
            {
                reverse(s.begin() + i, s.begin() + i + k);
            }
        }

        return s;
    }
};