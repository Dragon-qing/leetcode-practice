/*
 * @Author: Dragon-qing
 * @Date: 2026-03-23
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\1594\solution.cpp
 * @Description: 矩阵，动态规划
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1594 lang=cpp
 *
 * [1594] 矩阵的最大非负积
 */

// @lc code=start
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<long long>> dpMax(m, vector<long long>(n));
        vector<vector<long long>> dpMin(m, vector<long long>(n));
        int MOD = 1e9 + 7;
        dpMax[0][0] = dpMin[0][0] = grid[0][0];
        // 第一列
        for (int i = 1; i < m; i++)
            dpMax[i][0] = dpMin[i][0] = dpMax[i-1][0] * grid[i][0];
        
        // 第一行
        for (int j = 1; j < n; j++)
            dpMax[0][j] = dpMin[0][j] = dpMax[0][j-1] * grid[0][j];
        
        for (int r = 1; r < m; r++)
        {
            for (int c = 1; c < n; c++)
            {
                if (grid[r][c] >= 0)
                {
                    dpMax[r][c] = max(dpMax[r - 1][c], dpMax[r][c - 1]) * grid[r][c];
                    dpMin[r][c] = min(dpMin[r - 1][c], dpMin[r][c - 1]) * grid[r][c];
                }
                else
                {
                    dpMax[r][c] = min(dpMin[r - 1][c], dpMin[r][c - 1]) * grid[r][c];
                    dpMin[r][c] = max(dpMax[r - 1][c], dpMax[r][c - 1]) * grid[r][c];
                }
            }
        }
        if (dpMax[m-1][n-1] < 0) dpMax[m-1][n-1] = -1;

        return dpMax[m-1][n-1] % MOD;
    }
};
// @lc code=end

int main()
{
    vector<vector<int>> v = {
        {-1,-2,-3},{-2,-3,-3},{-3,-3,-2}
    };
    Solution s;
    s.maxProductPath(v);
    return 0;
}
