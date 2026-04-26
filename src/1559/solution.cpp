/*
 * @Author: Dragon-qing
 * @Date: 2026-04-26
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\1559\solution.cpp
 * @Description: 二维网格图中探测环，DFS
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1559 lang=cpp
 *
 * [1559] 二维网格图中探测环
 */

// @lc code=start
static constexpr array<array<int, 2>, 4> DIRS = {{{-1, 0}, {1, 0}, {0, 1}, {0, -1}}};
class Solution {
public:
    bool dfs(vector<vector<char>>& grid, int row, int col, int prex, int prey)
    {
        visit[row * grid[0].size() + col] = true;
        for (auto [dx, dy] : DIRS)
        {
            int x = row - dx;
            int y = col - dy;
            if ((x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size())
                && grid[row][col] == grid[x][y] && (prex != x || prey != y)
                && (visit[x * grid[0].size() + y] || dfs(grid, x, y, row, col)))
            {
                return true;
            }
        }

        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        visit.resize(m * n, false);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++) {
                if (!visit[i * n + j] && dfs(grid, i, j, -1, -1))
                {
                    return true;
                }
            }
        }
        return false;
    }
private:
    vector<bool> visit;
};
// @lc code=end

