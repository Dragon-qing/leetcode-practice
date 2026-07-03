/*
 * @Author: Dragon-qing
 * @Date: 2026-07-02
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3286\solution.cpp
 * @Description: 0-1BFS
 */

#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3286 lang=cpp
 *
 * [3286] 穿越网格图的安全路径
 */

// @lc code=start
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        deque<pair<int, int>> q;
        vector<vector<int>> dis(m, vector<int>(n, INT32_MAX));
        dis[0][0] = grid[0][0];
        
        q.push_back({0, 0});
        while (!q.empty()) {
            auto& [i, j] = q.back();
            q.pop_back();
            for (auto dir : dirs) {
                int x = i + dir[0];
                int y = j + dir[1];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    int cost = grid[x][y];
                    if (dis[i][j] + cost < dis[x][y]) {
                        dis[x][y] = dis[i][j] + cost;
                        cost == 0 ? q.push_back({x, y}) : q.push_front({x, y});
                    }
                }
            }
        }

        return health - dis[m - 1][n - 1] > 0;
    }

private:
    static constexpr int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
};
// @lc code=end

int main()
{
    Solution s;
    vector<vector<int>> grid = {
        {0,1,0,0,0},{0,1,0,1,0},{0,0,0,1,0}
    };
    cout << s.findSafeWalk(grid, 1);
    return 0;
}
