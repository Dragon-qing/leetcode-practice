/*
 * @Author: Dragon-qing
 * @Date: 2026-09-07
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\322\solution.cpp
 * @Description: 动态规划
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        ranges::sort(coins);

        vector<int> dp(amount + 1, -1);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            int mount = INT32_MAX;
            for (int coin : coins) {
                if (i - coin >= 0) {
                    if (dp[i - coin] == -1) continue;
                    mount = min(mount, dp[i - coin] + 1);
                }
            }
            if (mount == INT32_MAX) {
                dp[i] = -1;
            } else {
                dp[i] = mount;
            }
        }

        return dp[amount];
    }
};
// @lc code=end

