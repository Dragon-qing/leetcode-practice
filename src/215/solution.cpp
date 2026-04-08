/*
 * @Author: Dragon-qing
 * @Date: 2026-04-08
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\215\solution.cpp
 * @Description: 数组中的第K个最大元素，大根堆
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pri_q(nums.begin(), nums.end());
        for (auto _ : views::iota(0, k - 1))
        {
            pri_q.pop();
        }
        return pri_q.top();
    }
};
// @lc code=end

