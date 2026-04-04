/*
 * @Author: Dragon-qing
 * @Date: 2026-04-04
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\2087\solution.cpp
 * @Description: 贪心算法，矩阵
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=2087 lang=cpp
 *
 * [2087] 网格图中机器人回家的最小代价
 */

// @lc code=start
class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int startX = startPos[0];
        int startY = startPos[1];
        int endX = homePos[0];
        int endY = homePos[1];

        int res = 0;
        if (startX < endX)
        {
            for (startX += 1; startX <= endX; startX++)
            {
                res += rowCosts[startX];
            }

        }
        else
        {
            for (startX -= 1; startX >= endX; startX--)
            {
                res += rowCosts[startX];
            }
        }
        if (startY < endY)
        {
            for (startY += 1; startY <= endY; startY++)
            {
                res += colCosts[startY];
            }
        }
        else
        {
            for (startY -= 1; startY >= endY; startY--)
            {
                res += colCosts[startY];
            }
        }

        return res;
    }
};
// @lc code=end

