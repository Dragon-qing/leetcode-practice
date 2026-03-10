/*
 * @Author: Dragon-qing
 * @Date: 2026-03-10
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3130\solution.cpp
 * @Description: 动态规划
 * @note: 与3129解题思路一致
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3130 lang=cpp
 *
 * [3130] 找出所有稳定的二进制数组 II
 */

// @lc code=start
int dp[1001][1001][2];
class Solution {
    public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1e9 + 7;
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= min(zero, limit); i++)
        {
            dp[i][0][0] = 1;
        }
        for (int j = 1; j <= min(one, limit); j++)
        {
            dp[0][j][1] = 1;
        }

        for (int i = 1; i <= zero; i++)
        {
            for (int j = 1; j <= one; j++)
            {
                // 填0
                dp[i][j][0] = (dp[i - 1][j][1] + dp[i - 1][j][0]) % MOD;
                if (i > limit)
                {
                    dp[i][j][0] = (dp[i][j][0] - dp[i - 1 - limit][j][1] + MOD) % MOD;
                }
                // 填1
                dp[i][j][1] = (dp[i][j - 1][1] + dp[i][j - 1][0]) % MOD;
                if (j > limit)
                {
                    dp[i][j][1] = (dp[i][j][1] - dp[i][j - 1 - limit][0] + MOD) % MOD;
                }

            }
        }

        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};
// @lc code=end

int main()
{
    Solution s;
    cout << s.numberOfStableArrays(1, 2, 1);
    return 0;
}