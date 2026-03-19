/*
 * @Author: Dragon-qing
 * @Date: 2026-03-19
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3212\solution.cpp
 * @Description: 矩阵、前缀和
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3212 lang=cpp
 *
 * [3212] 统计 X 和 Y 频数相等的子矩阵数量
 */

// @lc code=start
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> sumArr(n);
        unordered_map<char, int> dict = {
            {'X', 1},
            {'Y', -1},
            {'.', 0}
        };
        vector<bool> xFlag(n, false); // 含X标志
        int ans = 0;

        for (int r = 0; r < m; r++)
        {
            int sum = 0;
            for (int c = 0; c < n; c++)
            {
                sumArr[c] += dict[grid[r][c]];
                sum += sumArr[c];
                if (grid[r][c] == 'X' || (c > 0 && xFlag[c - 1]))
                {
                    xFlag[c] = true;
                }
                if (xFlag[c] && sum == 0)
                {
                    ans += 1;
                }
            }
        }

        return ans;
    }
};
// @lc code=end

