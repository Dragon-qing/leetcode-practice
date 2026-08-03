/*
 * @Author: Dragon-qing
 * @Date: 2026-08-03
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\1406\solution.cpp
 * @Description: 动态规划
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1406 lang=cpp
 *
 * [1406] 石子游戏 III
 */

// @lc code=start
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> suffixSum(n); // 后缀和
        
        suffixSum[n - 1] = stoneValue[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + stoneValue[i];
        }

        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int bestChoice = dp[i + 1]; // 对手的最优选择
            for (int j = i + 2; j <= i + 3 && j <= n; j++) {
                bestChoice = min(bestChoice, dp[j]);
            }
            dp[i] = suffixSum[i] - bestChoice; // 当前最优选择
        }

        int total = suffixSum[0]; // 石子总数

        if (dp[0] * 2 == total) {
            return "Tie";
        }
        if (dp[0] * 2 < total) {
            return "Bob";
        } else {
            return "Alice";
        }
    }
};
// @lc code=end

