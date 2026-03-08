/*
 * @Author: Dragon-qing
 * @Date: 2026-03-08
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\459\main.cpp
 * @Description: 字符串，kmp，拼接搜索
 */
#include <bits/stdc++.h>
using namespace std;

// 拼接查找 (如果是通过由它的一个子串重复多次构成，则s+s后中间肯定有一个s)
// class Solution {
// public:
//     bool repeatedSubstringPattern(string s) {
//         string ss = s + s;
//         ss.erase(ss.begin());
//         ss.erase(ss.end() - 1);
//         if (ss.find(s) != string::npos)
//         {
//             return true;
//         }
//         return false;
//     }
// };
// kmp
class Solution {
public:
    vector<int> GetNext(string pattern)
    {
        int j = -1;
        vector<int> next(pattern.size());
        next[0] = j;

        for (int i = 1; i < (int)pattern.size(); i++)
        {
            while (j >= 0 && pattern[j + 1] != pattern[i])
            {
                j = next[j];
            }
            if (pattern[j + 1] == pattern[i])
            {
                j++;
            }
            next[i] = j;
        }

        return next;
    }
    bool repeatedSubstringPattern(string s) {
        auto next = GetNext(s);
        int n = next.size();
        if (next[n - 1] != -1 && n % (n - (next[n - 1] + 1)) == 0) 
        {
            // next最后一个值不为-1，则说明s存在最长前后缀。
            // 如果s的长度能被(len-最长前后缀长度)整除说明s可以由n个该子串组成。
            return true;
        }
        return false;
    }
};
int main()
{
    Solution s;
    cout << s.repeatedSubstringPattern("123123123123");
    return 0;
}