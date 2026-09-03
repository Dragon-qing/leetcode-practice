/*
 * @Author: Dragon-qing
 * @Date: 2026-09-03
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3876\solution.cpp
 * @Description: 分类讨论
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3876 lang=cpp
 *
 * [3874] 构造奇偶一致的数组II
 */

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int oddNum = 0;
        int minValue = INT32_MAX;
        for (auto i : nums1) {
            if (i % 2) {
                oddNum++;
            }
            minValue = min(minValue, i);
        }

        if (oddNum != 0 && minValue % 2 == 0) {
            return false;
        }

        return true;
    }
};

// @lc code=end