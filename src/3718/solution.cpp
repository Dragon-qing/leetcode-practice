/*
 * @Author: Dragon-qing
 * @Date: 2026-08-25
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3718\solution.cpp
 * @Description: 模拟
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3718 lang=cpp
 *
 * [3718] 缺失的最小倍数
 */

// @lc code=start
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set hash(nums.begin(), nums.end());

        int ans = k;
        while (hash.contains(ans)) {
            ans += k;
        }

        return ans;
    }
};
// @lc code=end

