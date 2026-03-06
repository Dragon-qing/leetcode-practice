/*
 * @Author: Dragon-qing
 * @Date: 2026-03-06
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\344\main.cpp
 * @Description: 字符串，双指针
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }

        return;
    }
};