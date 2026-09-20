/*
 * @Author: Dragon-qing
 * @Date: 2026-09-20
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3498\solution.cpp
 * @Description: 模拟
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3498 lang=cpp
 *
 * [3498] 字符串的反转度
 */

// @lc code=start
class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        int index = 1;
        for (char c : s) {
            ans += index * (26 - (c - 'a'));
            index += 1;
        }

        return ans;
    }
};
// @lc code=end

