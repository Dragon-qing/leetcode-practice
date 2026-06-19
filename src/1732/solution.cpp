/*
 * @Author: Dragon-qing
 * @Date: 2026-06-19
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\1732\solution.cpp
 * @Description: 前缀和
 */
#include <bits/stdc++.h>
using namespace std;


/*
 * @lc app=leetcode.cn id=1732 lang=cpp
 *
 * [1732] 找到最高海拔
 */

// @lc code=start
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxHeight = 0;
        int height = 0;
        for (int h : gain)
        {
            height += h;
            maxHeight = max(maxHeight, height);
        }

        return maxHeight;
    }
};
// @lc code=end

