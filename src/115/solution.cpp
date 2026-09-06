/*
 * @Author: Dragon-qing
 * @Date: 2026-09-06
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\115\solution.cpp
 * @Description: 动态规划
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = t.size();
        int n = s.size();

        vector dp(m + 1, vector<unsigned long long>(n + 1, 0));
        for (int j = 0; j <= n; j++) {
            dp[0][j] = 1;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = i; j <= n; j++) {
                if (s[j - 1] == t[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }

        return dp[m][n];
    }
};
// @lc code=end

