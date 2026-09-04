/*
 * @Author: Dragon-qing
 * @Date: 2026-09-04
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\198\solution.cpp
 * @Description: 动态规划
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int x1 = 0;
        int x2 = nums[0];
        if (n == 1) {
            return x2;
        }

        int ans = INT32_MIN;
        for (int i = 1; i < n; i++) {
            ans = max(x2, x1 + nums[i]);
            x1 = x2;
            x2 = ans;
        }

        return ans;
    }
};
// @lc code=end

