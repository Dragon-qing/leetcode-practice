/*
 * @Author: Dragon-qing
 * @Date: 2026-03-25
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3546\solution.cpp
 * @Description: 矩阵，前缀和
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3546 lang=cpp
 *
 * [3546] 等和矩阵分割 I
 */

// @lc code=start
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<long long> result(max(m, n), 0);
        long long prefix = 0;
        long long suffix = 0;
        
        for (int i = 1; i < m; i++)
        {
            prefix += reduce(grid[i - 1].begin(), grid[i - 1].end(), 0ll);
            suffix += reduce(grid[m - i].begin(), grid[m - i].end(), 0ll);
            result[i] += prefix;
            result[m - i] -= suffix;
        }
        for (int i = 1; i < m; i++)
        {
            if (result[i] == 0)
            {
                return true;
            }
            else
            {
                result[i] = 0;
            }
        }
        prefix = 0;
        suffix = 0;
        for (int col = 1; col < n; col++)
        {
            prefix += accumulate(grid.begin(), grid.end(), 0ll, [col](long long acc, const vector<int> &row){
                return acc + row[col - 1];
            });
            suffix += accumulate(grid.begin(), grid.end(), 0ll, [col, n](long long acc, const vector<int>& row){
                return acc + row[n - col];
            });
            result[col] += prefix;
            result[n - col] -= suffix;
        }
        for (int i = 1; i < n; i++)
        {
            if (result[i] == 0)
            {
                return true;
            }
            else
            {
                result[i] = 0;
            }
        }

        return false;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<vector<int>> v = {
        {1,3},{2,4}
    };
    s.canPartitionGrid(v);
    return 0;
}
