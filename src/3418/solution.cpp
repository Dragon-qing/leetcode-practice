/*
 * @Author: Dragon-qing
 * @Date: 2026-04-02
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3418\solution.cpp
 * @Description: 动态规划，矩阵
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3418 lang=cpp
 *
 * [3418] 机器人可以获得的最大金币数
 */

// @lc code=start
class Solution
{
public:
    int maximumAmount(vector<vector<int>> &coins)
    {
        int m = coins.size();
        int n = coins[0].size();
        vector<vector<array<int, 3>>> dp(m, vector(n, array<int, 3>{INT32_MIN / 2, INT32_MIN / 2, INT32_MIN / 2}));
        dp[0][0][0] = coins[0][0];
        // 初始化
        for (int k = 1; k < 3; k++)
        {
            dp[0][0][k] = max(coins[0][0], 0);
        }
        for (int i = 1; i < m; i++)
        {
            dp[i][0][0] = dp[i - 1][0][0] + coins[i][0];
            for (int k = 1; k < 3; k++)
            {
                dp[i][0][k] = max(dp[i - 1][0][k - 1], dp[i - 1][0][k] + coins[i][0]);
            }
        }
        for (int j = 1; j < n; j++)
        {
            dp[0][j][0] = dp[0][j - 1][0] + coins[0][j];
            for (int k = 1; k < 3; k++)
            {
                dp[0][j][k] = max(dp[0][j - 1][k - 1], dp[0][j - 1][k] + coins[0][j]);
            }
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i][j - 1][0]) + coins[i][j];
                for (int k = 1; k < 3; k++)
                {
                    dp[i][j][k] = max(max(dp[i - 1][j][k] + coins[i][j], dp[i - 1][j][k - 1]),
                                      max(dp[i][j - 1][k] + coins[i][j], dp[i][j - 1][k - 1]));
                }
            }
        }

        return dp[m - 1][n - 1][2];
    }
};
// @lc code=end
