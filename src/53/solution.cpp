/*
 * @Author: Dragon-qing
 * @Date: 2026-03-10
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\53\solution.cpp
 * @Description: array,dynamicplan,分治
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int *dp = new int[n]; // dp[i]：以nums[i]结尾的最大子数组和
        memset(dp, INT32_MIN, n);
        int maxValue = nums[0];
        dp[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]); // 动态规划转移方程
            maxValue = max(dp[i], maxValue);
        }
        return maxValue;
    }
};
// @lc code=end

