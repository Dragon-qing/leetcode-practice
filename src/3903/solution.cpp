/*
 * @Author: Dragon-qing
 * @Date: 2026-09-04
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3903\solution.cpp
 * @Description: 前缀和
 */
#include <bits/stdc++.h>
using namespace std;


/*
 * @lc app=leetcode.cn id=3876 lang=cpp
 *
 * [3903] 最小稳定下标I
 */

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> suffix(n, 0);
        suffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = min(suffix[i + 1], nums[i]);
        }

        int prefixMax = INT32_MIN;
        
        for (int i = 0; i < n; i++) {
            prefixMax = max(prefixMax, nums[i]);
            int t = prefixMax - suffix[i];
            if (t <= k) {
                return i;
            }
        }

        return -1;
    }
};
 // @lc code=end

 int main()
 {
    Solution s;
    vector<int> nums = {0, 0};
    s.firstStableIndex(nums, 0);
    return 0;
 }
 