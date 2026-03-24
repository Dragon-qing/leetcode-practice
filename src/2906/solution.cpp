/*
 * @Author: Dragon-qing
 * @Date: 2026-03-24
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\2906\solution.cpp
 * @Description: 矩阵，前缀和
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=2906 lang=cpp
 *
 * [2906] 构造乘积矩阵
 */

// @lc code=start
class Solution {
public:
    /**
     * @brief: 获取前一个元素
     * @param {int} r
     * @param {int} c
     * @param {vector<vector<int>>&} grid
     * @return {int}
     */
    int GetPreElement(int r, int c, const vector<vector<int>>& grid)
    {
        int prev = -1;
        int n = grid[0].size();

        if (c > 0) {
            prev = grid[r][c - 1];
        } else if (r > 0) {
            prev = grid[r - 1][n - 1];
        }
        return prev;
    }
    /**
     * @brief: 获取后一个元素
     * @param {int} r
     * @param {int} c
     * @param {vector<vector<int>>&} grid
     * @return {int}
     */    
    int GetNextElement(int r, int c, const vector<vector<int>>& grid)
    {
        int next = -1;
        int m = grid.size();
        int n = grid[0].size();
        if (c < n - 1) {
            next = grid[r][c + 1];      // 同一行右边
        } else if (r < m - 1) {
            next = grid[r + 1][0];      // 下一行第一个
        }
        return next;
    }
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int MOD = 12345;
        vector<int> prefix(m * n), suffix(m * n);
        vector<vector<int>> p(m, vector<int>(n));
        prefix[0] = 1;
        suffix[m * n - 1] = 1;
        // 填写前缀乘积和后缀乘积
        for (int r = 0; r < m; r++)
        {
            for (int c = 0; c < n; c++)
            {
                int idx = r * n + c;
                int range = m * n - 1;
                if (idx == 0)
                {
                    continue;
                }
                prefix[idx] = (prefix[idx - 1] % MOD) * (GetPreElement(r, c, grid) % MOD) % MOD;
                suffix[range - idx] = (suffix[range - idx + 1] % MOD) * (GetNextElement(m - r - 1, n - 1 -c, grid) % MOD) % MOD;
            }
        }

        for (int r = 0; r < m; r++)
        {
            for (int c = 0; c < n; c++)
            {
                int idx = r * n + c;

                p[r][c] = prefix[idx] * suffix[idx] % MOD;
            }
        }
        return p;
    }
};

// @lc code=end

int main()
{
    vector<vector<int>> v = {
        {1,2},{3,4}
    };
    Solution s;
    s.constructProductMatrix(v);
    return 0;
}
