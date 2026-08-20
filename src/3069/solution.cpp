/*
 * @Author: Dragon-qing
 * @Date: 2026-08-20
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3069\solution.cpp
 * @Description: 模拟
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3069 lang=cpp
 *
 * [3069] 将元素分配到两个数组中 I
 */

// @lc code=start
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        
        int left = 0;
        int right = 1;

        vector<int> result;
        result.push_back(nums[0]);
        vector<int> tmp;
        tmp.push_back(nums[1]);

        for (int i = 2; i < n; i++) {
            if (nums[left] > nums[right]) {
                result.emplace_back(nums[i]);
                left = i;
            } else {
                tmp.emplace_back(nums[i]);
                right = i;
            }
        }
        result.insert(result.end(), tmp.begin(), tmp.end());

        return result;
    }
};
// @lc code=end

