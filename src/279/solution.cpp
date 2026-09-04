/*
 * @Author: Dragon-qing
 * @Date: 2026-09-04
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\279\solution.cpp
 * @Description: 动态规划
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            int t = INT32_MAX;
            for (int j = 1; j * j <= i; j++) {
                t = min(t, dp[i - j * j] + 1);
            }
            dp[i] = t;
        }

        return dp[n];
    }
};
// @lc code=end

