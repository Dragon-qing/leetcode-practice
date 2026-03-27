/*
 * @Author: Dragon-qing
 * @Date: 2026-03-27
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\2946\solution.cpp
 * @Description: 矩阵，模拟
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=2946 lang=cpp
 *
 * [2946] 循环移位后的矩阵相似检查
 */

// @lc code=start
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        if (k % n == 0) return true; // 回到原位置直接返回
        int move = k % n;
        for (int r = 0; r < m; r++)
        {
            for (int c = 0; c < n; c++)
            {
                int movedC = 0;
                if (m & 1) // 偶数行
                {
                    movedC = (c - move + n) % n;
                } 
                else
                {
                    movedC = (c + move) % n;
                }
                if (mat[r][c] != mat[r][movedC])
                {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

