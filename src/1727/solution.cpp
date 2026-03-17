/*
 * @Author: Dragon-qing
 * @Date: 2026-03-17
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\1727\solution.cpp
 * @Description: 矩阵,贪心，排序
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1727 lang=cpp
 *
 * [1727] 重新排列后的最大子矩阵
 */

// @lc code=start
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> height(n, 0);
        int res = 0;
        for (int r = 0; r < m; r++)
        {
            for (int c = 0; c < n; c++)
            {
                if (matrix[r][c] == 0)
                {
                    height[c] = 0;
                }
                else
                {
                    height[c] += 1;
                }
            }
            vector<int> heightCopy = height;

            ranges::sort(heightCopy, greater());
            for (int i = 0; i < n; i++)
            {
                res = max(res, (i+1)*heightCopy[i]);
            }
        }
        return res;
    }
};
// @lc code=end

