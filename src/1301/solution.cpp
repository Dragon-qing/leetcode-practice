/*
 * @Author: Dragon-qing
 * @Date: 2026-07-05
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\1301\solution.cpp
 * @Description: 动态规划
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1301 lang=cpp
 *
 * [1301] 最大得分的路径数目
 */

// @lc code=start
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        const int MOD = 1e9 + 7;
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> maxSum(m + 1, vector<int>(n + 1, INT32_MIN));
        vector ways(m + 1, vector<int>(n + 1));
        maxSum[0][0] = 0;
        ways[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char c = board[i][j];
                if (c == 'X') {
                    continue;
                }

                maxSum[i + 1][j + 1] = max({maxSum[i][j], maxSum[i + 1][j], maxSum[i][j + 1]});

                int s = maxSum[i + 1][j + 1];

                long long w = 0;
                
                if (s == maxSum[i][j]) {
                    w += ways[i][j];
                }
                if (s == maxSum[i + 1][j]) {
                    w += ways[i + 1][j];
                }
                if (s == maxSum[i][j + 1]) {
                    w += ways[i][j + 1];
                }

                ways[i + 1][j + 1] = w % MOD;
                if (c >= '1' && c <= '9') {
                    maxSum[i + 1][j + 1] += c - '0';
                }
            }
        }

        return maxSum[m][n] < 0 ? vector<int>{0, 0} : vector<int>{maxSum[m][n], ways[m][n]};
    }
};
// @lc code=end

