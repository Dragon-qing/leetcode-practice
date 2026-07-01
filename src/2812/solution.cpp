/*
 * @Author: Dragon-qing
 * @Date: 2026-07-01
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\2812\solution.cpp
 * @Description: 并查集，多源BFS
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=2812 lang=cpp
 *
 * [2812] 找出最安全路径
 */

// @lc code=start
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector dis(n, vector(n, -1));
        vector<pair<int, int>> q;
        // 遍历查找为小偷单元格
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dis[i][j] = 0;
                    q.push_back({i, j});
                }
            }
        }

        vector<vector<pair<int, int>>> groups = {q};
        // 多源BFS
        while (!q.empty()) {
            auto tmp = move(q);
            for (auto& [i, j] : tmp) {
                for (auto& [dx, dy] : dirs) {
                    int x = i + dx, y = j + dy;
                    if (0 <= x && x < n && 0 <= y && y < n && dis[x][y] < 0) {
                        dis[x][y] = groups.size();
                        q.push_back({x, y});
                    }
                }
            }
            groups.push_back(q);
        }

        // 并查集
        fa.resize(n * n);
        ranges::iota(fa, 0);

        for (int ans = (int) groups.size() - 2; ans >= 0; ans--) {
            for (auto& [i, j] : groups[ans]) {
                for (auto& [dx, dy] : dirs) {
                    int x = i + dx;
                    int y = j + dy;
                    if (0 <= x && x < n && 0 <= y && y < n && dis[x][y] >= ans) {
                        fa[find(x * n + y)] = find(i * n + j);
                    }
                }
            }
            if (find(0) == find(n * n - 1)) {return ans;}
        }

        return 0;
    }

private:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<int> fa;

    int find (int x)
    {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<vector<int>> grid = {
        {1,0,0},{0,0,0},{0,0,1}
    };
    cout << s.maximumSafenessFactor(grid);
    return 0;
}
