/*
 * @Author: Dragon-qing
 * @Date: 2026-04-05
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\657\solution.cpp
 * @Description: 字符串，模拟
 */

#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=657 lang=cpp
 *
 * [657] 机器人能否返回原点
 */

// @lc code=start
class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for (char c : moves)
        {
            if (c == 'U')
            {
                y += 1;
            }
            else if(c == 'D')
            {
                y -= 1;
            }
            else if (c == 'L')
            {
                x -= 1;
            }
            else if (c == 'R')
            {
                x += 1;
            }
        }
        return x == 0 && y == 0 ? true : false;
    }
};
// @lc code=end

