/*
 * @Author: Dragon-qing
 * @Date: 2026-08-17
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3702\solution.cpp
 * @Description: 数学
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3702 lang=cpp
 *
 * [3702] 按位异或非零的最长子序列
 */

// @lc code=start
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xorx = 0;
        int ory = 0;
        for (int i : nums) {
            xorx ^= i;
            ory |= i;
        }

        return ory ? nums.size() - !xorx : 0;
    }
};
// @lc code=end

