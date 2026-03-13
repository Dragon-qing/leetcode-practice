/*
 * @Author: Dragon-qing
 * @Date: 2026-03-11
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\240\solution.cpp
 * @Description: 矩阵、二分查找
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int colL = 0, colR = n - 1;
        while (colL <= colR)
        {
            int mid = (colL + colR) / 2;
            if (matrix[0][mid] == target)
            {
                return true;
            }
            else if (matrix[0][mid] < target)
            {
                colL = mid + 1;
            }
            else if (matrix[0][mid] > target)
            {
                colR = mid - 1;
            }
        }
        int range = 0;
        if (colL >= n)
        {
            range = colR;
        }
        else
        {
            range = matrix[0][colL] < target ? colL : colR;
        }
        for (int i = 0; i <= range; i++)
        {
            if (matrix[m - 1][i] < target)
            {
                continue;
            }
            int rowl = 0, rowr = m - 1;
            while (rowl <= rowr)
            {
                int mid = (rowl + rowr) / 2;
                if (matrix[mid][i] == target)
                {
                    return true;
                }
                else if (matrix[mid][i] < target)
                {
                    rowl = mid + 1;
                }
                else
                {
                    rowr = mid - 1;
                }

            }
        }
        return false;
    }
};
// @lc code=end

