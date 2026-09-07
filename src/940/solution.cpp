/*
 * @Author: Dragon-qing
 * @Date: 2026-09-07
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\940\solution.cpp
 * @Description: 动态规划
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=940 lang=cpp
 *
 * [940] 不同的子序列 II
 */

// @lc code=start
class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int> dp(26, 0);
        const int MOD = 1e9 + 7;
        
        for (int i = 0; i < n; i++) {
            dp[s[i] - 'a'] = reduce(dp.begin(), dp.end(), 1LL) % MOD;
        }

        return reduce(dp.begin(), dp.end(), 0LL) % MOD;
    }
};
// @lc code=end

