/*
 * @Author: Dragon-qing
 * @Date: 2026-09-10
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\300\solution.cpp
 * @Description: 动态规划
 * @Note: 使用贪心和二分查找可以更快
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);

        int minValueIdx = 0;
        int ans = 1;

        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[minValueIdx]) {
                minValueIdx = i;
                continue;
            }

            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> nums = {0,1,0,3,2,3};
    s.lengthOfLIS(nums);
    return 0;
}
