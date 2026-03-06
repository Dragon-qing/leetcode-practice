/*
 * @Author: Dragon-qing
 * @Date: 2026-03-06
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\LCR122\main.cpp
 * @Description: 字符串
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string pathEncryption(string path) {
        for (char &c : path)
        {
            if (c == '.')
            {
                c = ' ';
            }
        }
        return path;
    }
};