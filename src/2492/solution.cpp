/*
 * @Author: Dragon-qing
 * @Date: 2026-07-04
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\2492\solution.cpp
 * @Description: dfs, 连通图
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=2492 lang=cpp
 *
 * [2492] 两个城市间路径的最小分数
 */

// @lc code=start
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        p.resize(n + 1);
        for (auto &e : roads) {
            int x = e[0];
            int y = e[1];
            int dis = e[2];
            p[x].emplace_back(y, dis);
            p[y].emplace_back(x, dis);
        }

        visited.resize(n + 1, false);
        ans = INT32_MAX;
        dfs(1);

        return ans;
    }

    void dfs(int cur)
    {
        visited[cur] = true;

        for (auto &[y, dis] : p[cur]) {
            ans = min(dis, ans);
            if (!visited[y]) {
                dfs(y);
            }
        }
    }

private:
    vector<vector<pair<int, int>>> p;
    vector<bool> visited;
    int ans;
};
// @lc code=end

int main()
{
    Solution s;
    vector<vector<int>> roads = {
        {1,2,9},{2,3,6},{2,4,5},{1,4,7}
    };
    s.minScore(4, roads);
    return 0;
}
