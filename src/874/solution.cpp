/*
 * @Author: Dragon-qing
 * @Date: 2026-04-06
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\874\solution.cpp
 * @Description: 哈希函数，模拟
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=874 lang=cpp
 *
 * [874] 模拟行走机器人
 */

// @lc code=start
class Solution
{
public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        unordered_set<int> hashSet;
        int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 四个方向坐标增量
        int dir = 0; // 北东南西
        const int K = 60'001; // 哈希函数系数
        int curX = 0, curY = 0;
        // 记录障碍物位置
        for (auto &obstacle : obstacles)
        {
            hashSet.emplace(obstacle[0] * K + obstacle[1]);
        }
        int maxDis = 0;
        for (int cmd : commands)
        {
            if (cmd < 0)
            {
                dir += cmd == -1 ? 1 : 3;
                dir %= 4;
            }
            else
            {
                for (int i = 0; i < cmd; i++)
                {
                    if (hashSet.contains((curX + dirs[dir][0]) * K + curY + dirs[dir][1]))
                    {
                        break;
                    }
                    curX += dirs[dir][0];
                    curY += dirs[dir][1];
                    maxDis = max(curX * curX + curY * curY, maxDis);
                }
            }
        }
        return maxDis;
    }
};
// @lc code=end
