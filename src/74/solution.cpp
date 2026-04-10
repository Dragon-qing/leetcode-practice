/*
 * @Author: Dragon-qing
 * @Date: 2026-04-10
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\74\solution.cpp
 * @Description: 搜索二维矩阵，二分查找
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int start = 0, end = m * n - 1;

        int mid = 0;
        while (start <= end)
        {
            mid = (start + end) / 2;
            int r = mid / n;
            int c = mid % n;

            if (matrix[r][c] == target) return true;
            else if (matrix[r][c] < target) start = mid + 1;
            else end = mid - 1;
        }

        return false;
    }
};
// @lc code=end

