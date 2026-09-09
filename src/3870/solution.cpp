/*
 * @Author: Dragon-qing
 * @Date: 2026-09-08
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3870\solution.cpp
 * @Description: 模拟
 */

#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3870 lang=cpp
 *
 * [3870] 统计范围内的逗号
 */

class Solution {
public:
    int countCommas(int n) {
        int ans = n - 1000 + 1;
        return ans > 0 ? ans : 0;
    }
};
 // @lc code=end