/*
 * @Author: Dragon-qing
 * @Date: 2026-03-21
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3643\solution.cpp
 * @Description: 矩阵，垂直翻转
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3643 lang=cpp
 *
 * [3643] 垂直翻转子矩阵
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m = grid.size();
        int n = grid[0].size();
        for (int xoffset = 0; xoffset < k / 2; xoffset++)
        {
            for (int yoffset = 0; yoffset < k; yoffset++)
            {
                swap(grid[x + xoffset][y + yoffset], grid[x + k - 1 - xoffset][y + yoffset]);
            }
        }
        return grid;
    }
};
// @lc code=end

