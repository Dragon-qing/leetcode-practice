/*
 * @Author: Dragon-qing
 * @Date: 2026-09-23
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\1658\solution.cpp
 * @Description: 滑动窗口
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1658 lang=cpp
 *
 * [1658] 将 x 减到 0 的最小操作数
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = reduce(nums.begin(), nums.end()) - x;

        if (target < 0) {
            return -1;
        }
        int sum = 0, ans = -1, left = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            while (sum > target) {
                sum -= nums[left++];
            }
            if (sum == target) {
                ans = max(ans, i - left + 1);
            }
        }
        return ans == -1 ? -1 : n - ans;
    }
};
// @lc code=end

