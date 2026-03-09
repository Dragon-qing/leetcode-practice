/*
 * @Author: Dragon-qing
 * @Date: 2026-03-09
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3129\solution.cpp
 * @Description: 动态规划，前缀和
 */
#include <bits/stdc++.h>
using namespace std;


/*
 * @lc app=leetcode.cn id=3129 lang=cpp
 *
 * [3129] 找出所有稳定的二进制数组 I
 */

// @lc code=start
class Solution {
public:
    /**
     * @brief: 差分动态规划实现
     * @param {int} zero
     * @param {int} one
     * @param {int} limit
     * @return {*}
     */
    int numberOfStableArrays(int zero, int one, int limit) {
        // 三维i,j,k分别代表0的个数，1的个数，结尾是0/1
        const int MOD = 1e9 + 7;
        vector<vector<vector<int>>> dp = vector<vector<vector<int>>>(zero + 1, vector<vector<int>>(one + 1, vector<int>(2, 0)));
        for (int i = 1 ; i <= min(zero, limit); i++)
        {
            dp[i][0][0] = 1;
        }
        for (int j = 1 ; j <= min(one, limit); j++)
        {
            dp[0][j][1] = 1;
        }
        for (int i = 1; i <= zero; i++)
        {
            for (int j = 1; j <= one; j++)
            {
                //末尾➕0
                dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % MOD;
                if ( i > limit) // 减去不合规的情况
                {
                    dp[i][j][0] = (dp[i][j][0] - dp[i - 1 -limit][j][1] + MOD) % MOD;
                }
                //末尾➕1
                dp[i][j][1] = (dp[i][j - 1][0] + dp[i][j - 1][1]) % MOD;
                if ( j > limit) // 减去不合规的情况
                {
                    dp[i][j][1] = (dp[i][j][1] - dp[i][j - 1 -limit][0] + MOD) % MOD;
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
    cout << s.numberOfStableArrays(20, 15, 75);
    return 0;
}