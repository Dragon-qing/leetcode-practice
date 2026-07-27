/*
 * @Author: Dragon-qing
 * @Date: 2026-07-26
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\628\solution.cpp
 * @Description: 模拟
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=628 lang=cpp
 *
 * [628] 三个数的最大乘积
 */

// @lc code=start
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        ranges::sort(nums);
        int n = nums.size();
        if (nums[0] >= 0 || nums[0] * nums[1] < 0) {
            // 全正或1个负数
            return nums[n - 3] * nums[n - 2] * nums[n - 1];
        }

        // 2个及以上负数
        return max({nums[0] * nums[1] * nums[n - 1], nums[0] * nums[1] * nums[2], nums[n - 3] * nums[n - 2] * nums[n - 1]});
    }
};
// @lc code=end

