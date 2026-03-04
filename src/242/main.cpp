/*
 * @Author: dragon-qing
 * @Date: 2026-03-04
 * @LastEditors: dragon-qing
 * @FilePath: \leetcode\src\242\main.cpp
 * @Description: 哈希表，字符串
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int hash[26] = {};
        int loop = s.size();
        while (loop--)
        {
            char c = s.at(loop);
            hash[c - 'a'] += 1;
        }
        loop = t.size();
        while (loop--)
        {
            char c = t.at(loop);
            hash[c - 'a'] -= 1;
        }
        for (int i : hash)
        {
            if (i != 0)
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution s;
    cout << s.isAnagram("anagram", "nagaram");
    return 0;
}