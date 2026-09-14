/*
 * @Author: Dragon-qing
 * @Date: 2026-09-14
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\152\solution.cpp
 * @Description: 动态规划
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        long long minValue = nums[0];
        long long maxValue = nums[0];
        long long tmp = 0;
        long long ans = maxValue;
        for(int i = 1; i < n; i++) {
            tmp = minValue;
            minValue = min({minValue * nums[i], 1ll * nums[i], maxValue * nums[i]});
            maxValue = max({tmp * nums[i], 1ll * nums[i], maxValue * nums[i]});
            ans = max(ans, maxValue);
        }

        return (int)ans;
    }
};
// @lc code=end

