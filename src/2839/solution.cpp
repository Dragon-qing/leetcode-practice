/*
 * @Author: Dragon-qing
 * @Date: 2026-03-29
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\2839\solution.cpp
 * @Description: 字符串，哈希表
 * @note: 使用两个二维哈希数组更快
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=2839 lang=cpp
 *
 * [2839] 判断通过操作能否让字符串相等 I
 */

// @lc code=start
class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        vector<int> hash(26, 0);
        for (char c : s1)
        {
            hash[c - 'a'] += 1;
        }
        for (char c : s2)
        {
            hash[c - 'a'] -= 1;
            if (hash[c - 'a'] < 0)
            {
                return false;
            }
        }
        for (int i = 0; i < 2; i++)
        {
            if (s1[i] != s2[i])
            {
                swap(s1[i], s1[i + 2]);
            }
        }
        return s1 == s2;
    }
};
// @lc code=end

int main()
{
    Solution s;
    s.canBeEqual("cmpr", "rmcp");
    return 0;
}

