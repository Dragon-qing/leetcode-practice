/*
 * @Author: Dragon-qing
 * @Date: 2026-07-20
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\1260\solution.cpp
 * @Description: 模拟
 */
#include <bits/stdc++.h>
#include "fmt/core.h"
#include "fmt/ranges.h"
using namespace std;

/*
 * @lc app=leetcode.cn id=1260 lang=cpp
 *
 * [1260] 二维网格迁移
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector ans(m, vector<int>(n));

        int size = m * n;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int p = (i * n + j + k) % size;
                ans[p / n][p % n] = grid[i][j];
            }
        }
        return ans;
    }
};

// @lc code=end

int main()
{
    Solution s;
    vector<vector<int>> grid = {{1,2,3},{4,5,6},{7,8,9}};
    auto ans = s.shiftGrid(grid, 1);
    for (auto v : ans) {
        fmt::println("{}", v);
    }
    return 0;
}
