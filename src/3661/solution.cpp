/*
 * @Author: Dragon-qing
 * @Date: 2026-04-03
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3661\solution.cpp
 * @Description: 二分查找，动态规划
 */

#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3661 lang=cpp
 *
 * [3661] 可以被机器人摧毁的最大墙壁数目
 */

// @lc code=start
class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        unordered_map<int, int> hashmap;
        for (int i = 0; i < n; i++)
        {
            hashmap[robots[i]] = i;
        }
        ranges::sort(robots);
        ranges::sort(walls);
        vector<int> left(n, 0), right(n, 0), nums(n, 0);
        int robotPos = 0, shootRangeL = 0, shootRangeR = 0, prevRobotPos = 0;
        for (int i = 0; i < n; i++)
        {
            robotPos = robots[i];
            // 向左射击
            if (i == 0)
            {
                shootRangeL = robotPos - distance[hashmap[robotPos]];
            }
            else
            {
                shootRangeL = max(robotPos - distance[hashmap[robotPos]], robots[i - 1] + 1);
            }
            left[i] = upper_bound(walls.begin(), walls.end(), robotPos) - lower_bound(walls.begin(), walls.end(), shootRangeL);
            // 向右射击
            if (i == n - 1)
            {
                shootRangeR = robotPos + distance[hashmap[robotPos]];
            }
            else
            {
                shootRangeR = min(robotPos + distance[hashmap[robotPos]], robots[i + 1] - 1);
            }
            right[i] = upper_bound(walls.begin(), walls.end(), shootRangeR) - lower_bound(walls.begin(), walls.end(), robotPos);
            // 两机器人之间的墙
            if (i == 0) continue;

            nums[i] = upper_bound(walls.begin(), walls.end(), robotPos) - lower_bound(walls.begin(), walls.end(), robots[i - 1]);
        }
        int curBotShootLeft = 0, curBotShootRight = 0, prevBotShootLeft = 0, prevBotShootRight = 0;
        prevBotShootLeft = left[0];
        prevBotShootRight = right[0];
        for (int i = 1; i < n; i++)
        {
            curBotShootLeft = max(prevBotShootLeft + left[i], prevBotShootRight - right[i - 1] + min(right[i - 1] + left[i], nums[i]));
            curBotShootRight = max(prevBotShootLeft + right[i], prevBotShootRight + right[i]);
            prevBotShootLeft = curBotShootLeft;
            prevBotShootRight = curBotShootRight;
        }

        return max(prevBotShootRight, prevBotShootLeft);
    }
};
// @lc code=end

