/*
 * @Author: Dragon-qing
 * @Date: 2026-03-11
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\48\solution.cpp
 * @Description: 模拟，矩阵
 * @note: 转置再垂直镜像也可以得到最终结果，并且不用额外的空间。
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        queue<int> q;
        int n = matrix.size();
        int loop = n / 2;
        int offset = 1;
        
        for (int i = 0; i < loop; i++)
        {
            int row = i;
            int col = i;
            int tmp = 0;
            for (; col < n - offset; col++)
            {
                q.push(matrix[row][col]);
            }
            for (; row < n - offset; row++)
            {
                q.push(matrix[row][col]);
                tmp = q.front();
                q.pop();
                matrix[row][col] = tmp;
            }
            for (; col > offset - 1; col--)
            {
                q.push(matrix[row][col]);
                tmp = q.front();
                q.pop();
                matrix[row][col] = tmp;
            }
            for (; row > offset - 1; row--)
            {
                q.push(matrix[row][col]);
                tmp = q.front();
                q.pop();
                matrix[row][col] = tmp;
            }
            for (; col < n - offset; col++)
            {
                tmp = q.front();
                q.pop();
                matrix[row][col] = tmp;
            }
            offset++;
        }
    }
};
// @lc code=end

