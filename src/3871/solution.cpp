/*
 * @Author: Dragon-qing
 * @Date: 2026-09-09
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3871\solution.cpp
 * @Description: 数学
 */

#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3871 lang=cpp
 *
 * [3871] 统计范围内的逗号II
 */

class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

        for (int low = 1000; low < n; low *= 1000) {
            ans += n - low + 1;
        }
        
        return ans;
    }
};
 // @lc code=end