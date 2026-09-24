/*
 * @Author: Dragon-qing
 * @Date: 2026-09-24
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3550\solution.cpp
 * @Description: 模拟
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3550 lang=cpp
 *
 * [3550] 数位和等于下标的最小下标
 */

// @lc code=start
class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (check(nums[i], i)) {
                return i;
            }
        }

        return -1;
    }

    bool check(int x, int index) {
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }

        return sum == index;
    }
};
// @lc code=end

