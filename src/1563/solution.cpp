/*
 * @Author: Dragon-qing
 * @Date: 2026-08-17
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\1563\solution.cpp
 * @Description: 动态规划，记忆化搜索
 */

#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1563 lang=cpp
 *
 * [1563] 石子游戏 V
 */

// @lc code=start
class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        // 计算前缀和
        for (int i = 1; i < n; i++) {
            stoneValue[i] += stoneValue[i - 1];
        }

        vector dp(n, vector<int>(n, -1));

        auto dfs = [&](this auto&& dfs, int i, int j) -> int {
            if (i >= j) {
                return 0;
            }

            if (dp[i][j] != -1) { // 使用记忆结果
                return dp[i][j];
            }

            int sum1 = 0;
            int sum2 = 0;
            int ans = 0;
            
            for (int x = i; x <= j; x++) {
                if (i == 0) {
                    sum1 = stoneValue[x];
                } else {
                    sum1 = stoneValue[x] - stoneValue[i - 1];
                }
                sum2 = stoneValue[j] - stoneValue[x];

                if (sum1 > sum2) {
                    ans = max(ans, sum2 + dfs(x + 1, j));
                } else if (sum1 < sum2) {
                    ans = max(ans, sum1 + dfs(i, x));
                } else {
                    ans = max(ans, max(dfs(i, x), dfs(x + 1, j)) + sum1);
                }
            }

            dp[i][j] = ans;
            return ans;
        };

        return dfs(0, n-1);
    }
};
// @lc code=end

