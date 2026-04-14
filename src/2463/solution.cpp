/*
 * @Author: Dragon-qing
 * @Date: 2026-04-14
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\2463\solution.cpp
 * @Description: 最小移动总距离，动态规划
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=2463 lang=cpp
 *
 * [2463] 最小移动总距离
 */

// @lc code=start
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int m = robot.size();
        int n = factory.size();
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, LONG_LONG_MAX / 2));

        for (int j = 0; j <= n; j++)
        {
            dp[0][j] = 0; // 没有机器人要修
        }

        for (int j = 1; j <= n; j++)
        {
            for (int i = 1; i <= m; i++)
            {
                dp[i][j] = dp[i][j - 1];
                long long res = 0;
                for (int k = 1; k <= min(i, factory[j - 1][1]); k++) // 枚举第j个工程收0-...个机器人的情况
                {
                    res += abs(robot[i - k] - factory[j - 1][0]);
                    dp[i][j] = min(dp[i][j], res + dp[i - k][j - 1]);
                }

            }
        }

        return dp[m][n];
    }
};
// @lc code=end
