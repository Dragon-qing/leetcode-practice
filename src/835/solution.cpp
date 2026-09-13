/*
 * @Author: Dragon-qing
 * @Date: 2026-09-13
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\835\solution.cpp
 * @Description: 数组，哈希
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=835 lang=cpp
 *
 * [835] 图像重叠
 */

// @lc code=start
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int ,int>> a, b; // 存储两个图中1的坐标
        int n = img1.size();
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (img1[r][c]) {
                    a.push_back({r, c});
                }
                if (img2[r][c]) {
                    b.push_back({r, c});
                }
            }
        }

        unordered_map<int, int> deltaMap;
        int ans = 0;
        for (auto &[x1, y1] : a) {
            for (auto &[x2, y2] : b) {
                int delta = (x2 - x1 + n) * 2 * n + (y2 - y1 + n);
                deltaMap[delta] += 1;
                ans = max(ans, deltaMap[delta]);
            }
        }

        return ans;
    }
};
// @lc code=end

