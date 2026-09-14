/*
 * @Author: Dragon-qing
 * @Date: 2026-09-14
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\836\solution.cpp
 * @Description: 几何
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=836 lang=cpp
 *
 * [836] 矩形重叠
 */

// @lc code=start
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        auto [x1, y1, x2, y2] = tuple{rec1[0], rec1[1], rec1[2], rec1[3]};
        auto [x3, y3, x4, y4] = tuple{rec2[0], rec2[1], rec2[2], rec2[3]};
        
        int width = max(0, min(x2, x4) - max(x1, x3));
        int heigh = max(0, min(y2, y4) - max(y1, y3));

        return width * heigh > 0 ? true : false;
    }
};
// @lc code=end

