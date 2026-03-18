/*
 * @Author: Dragon-qing
 * @Date: 2026-03-18
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3070\solution.cpp
 * @Description: 矩阵，前缀和
 * @note: 可以改用一位数组存储列和，优化时间和空间
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3070 lang=cpp
 *
 * [3070] 元素和小于等于 k 的子矩阵的数目
 */

// @lc code=start
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> colSum(m, vector<int>(n));
        int res = 0;
        for (int r = 0; r < m; r++)
        {
            int sum = 0;
            for (int c = 0; c < n; c++)
            {
                int tmp = grid[r][c];
                if (r > 0)
                {
                    colSum[r][c] = colSum[r - 1][c] + tmp;
                    sum = tmp + sum + colSum[r - 1][c];
                }
                else
                {
                    colSum[r][c] = tmp;
                    sum += tmp;
                }
                
                if (sum <= k)
                {
                    res += 1;
                }
                else
                {
                    break;
                }
            }
            if (colSum[r][0] > k)
            {
                break;
            }
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<vector<int>> vec = {
        {7,6,3},{6,6,1}
    };
    s.countSubmatrices(vec, 18);
    return 0;
}