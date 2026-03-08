/*
 * @Author: Dragon-qing
 * @Date: 2026-03-08
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\28\main.cpp
 * @Description: 字符串匹配，kmp算法
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @brief: 构建next数组
     * @note: 构建的next数组为前缀表统一减1(其他也有直接用前缀表作为next数组或把next数组右移一位,next[0]=-1的写法)
     * @param {string} needle 模式串
     * @return {vector<int>} next数组
     */
    vector<int> BuildNext(string needle)
    {
        int n = needle.size();
        vector<int> next(n ,0);
        int j = -1;
        next[0] = j;
        for (int i = 1; i < n; i++)
        {
            while(j >= 0 && needle[i] != needle[j + 1])
            {
                j = next[j];
            }
            if (needle[i] == needle[j + 1])
            {
                j++;
            }
            next[i] = j;
        }
        
        return next;
    }
    int strStr(string haystack, string needle) {
        int ans = -1;
        
        int j = -1;
        int m = haystack.size();
        int n = needle.size();
        vector<int> next = BuildNext(needle);
        for (int i = 0; i < m; i++)
        {
            while (j >= 0 && haystack[i] != needle[j + 1])
            {
                j = next[j];
            }
            if (haystack[i] == needle[j + 1])
            {
                j++;
            }
            if (j == n - 1) // 匹配完毕
            {
                ans = i - n;
                break;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.strStr("mississippi", "issip");
    return 0;
}