/*
 * @Author: Dragon-qing
 * @Date: 2026-03-05
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\383\main.cpp
 * @Description: 哈希表
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int hash[26] = {};
        for (char c : magazine)
        {
            hash[c - 'a'] += 1;
        }
        for (char c : ransomNote)
        {
            hash[c - 'a'] -= 1;
            if (hash[c - 'a'] < 0)
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    return 0;
}