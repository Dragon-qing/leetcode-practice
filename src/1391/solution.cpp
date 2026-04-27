/*
 * @Author: Dragon-qing
 * @Date: 2026-04-27
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\1391\solution.cpp
 * @Description: 检查网格中是否存在有效路径, 路径问题，dfs
 */
#include <bits/stdc++.h>
#include "fmt/base.h"
using namespace std;

/*
 * @lc app=leetcode.cn id=1391 lang=cpp
 *
 * [1391] 检查网格中是否存在有效路径
 */

// @lc code=start
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        visit.resize(m, std::vector<bool>(n, false));
        if (grid[0][0] == 5 && m * n != 1) {
            return false;
        } else if (grid[0][0] == 5 && m * n == 1) {
            return true;
        }
        
        int res = false;
        if (grid[0][0] == 4)
        {
            res = varify(grid, 4);
            visit.assign(m, std::vector<bool>(n, false));
            res = res | varify(grid, 2);
        }
        else
        {
            int in = 1;
            if (grid[0][0] == 2 || grid[0][0] == 6) in = 8;
            res = varify(grid, in);
        }
        
        return res;
    }
    
    bool varify(vector<vector<int>>& grid, int in)
    {
        const int id[6] = {5, 10, 3, 6, 9, 12}; // 从左边开始，按逆时针给路口编号，1,2,4,8。将两个路口值加起来组成id号
        int m = grid.size();
        int n = grid[0].size();
        int x = 0, y = 0;
        while (x != m - 1 || y != n - 1)
        {
            if (visit[x][y]) return false;
            visit[x][y] = true;
            int curid = id[grid[x][y] - 1];
            if ((curid & in) == 0) {
                return false;
            }
            int out = curid ^ in;
            move(x, y, in, out);
            if ((x < 0 || x >= m) || (y < 0 || y >= n)) {
                return false;
            }
            if ((id[grid[x][y] - 1] & in) == 0) {
                return false;
            }
        }
        return true;
    }
    void move(int &x, int &y, int &in, int out)
    {
        switch (out) {
        case 1:
            y--;
            in = 4;
            break;
        case 2:
            x++;
            in = 8;
            break;
        case 4:
            y++;
            in = 1;
            break;
        case 8:
            x--;
            in = 2;
            break;
        default:
            break;
        }
    }
private:
    vector<vector<bool>> visit;
};
// @lc code=end

int main()
{
    vector<vector<int>> grid = {{4, 1, 3},{6,1,2}};
    Solution s;
    s.hasValidPath(grid);
    return 0;
}
