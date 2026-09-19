/*
 * @Author: Dragon-qing
 * @Date: 2026-09-19
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\1401\solution.cpp
 * @Description: 几何
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1401 lang=cpp
 *
 * [1401] 圆和矩形是否有重叠
 */

// @lc code=start
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int x = min(max(xCenter, x1), x2) - (xCenter);
        int y = min(max(yCenter, y1), y2) - (yCenter);

        return x * x + y * y <= radius * radius;
    }
};
// @lc code=end

int main()
{
    Solution s;
    s.checkOverlap(1,1,1,-3,-3,3,3);
    return 0;
}
