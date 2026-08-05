/*
 * @Author: Dragon-qing
 * @Date: 2026-08-04
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3731\solution.cpp
 * @Description: 排序
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3731 lang=cpp
 *
 * [3731] 找出缺失的元素
 */

// @lc code=start
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        auto [minItem, maxItem] = ranges::minmax(nums);
        unordered_set hash(nums.begin(), nums.end());

        vector<int> ans;
        for (int i = minItem + 1; i < maxItem; i++) {
            if (!hash.contains(i)) {
                ans.emplace_back(i);
            }
        }

        return ans;
    }
};
// @lc code=end

