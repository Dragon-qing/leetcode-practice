/*
 * @Author: Dragon-qing
 * @Date: 2026-07-27
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\1464\solution.cpp
 * @Description: 排序
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1464 lang=cpp
 *
 * [1464] 数组中两元素的最大乘积
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int min1 = INT32_MAX;
        int min2 = INT32_MAX;
        int max1 = INT32_MIN;
        int max2 = INT32_MIN;

        for (int i : nums) {
            if (i < min1) {
                min2 = min1;
                min1 = i;
            } else if (i < min2) {
                min2 = i;
            }
            
            if (i > max1) {
                max2 = max1;
                max1 = i;
            } else if (i > max2) {
                max2 = i;
            }
        }

        int res1 = (min1 - 1) * (min2 - 1);
        int res2 = (max1 - 1) * (max2 - 1);

        return max(res1, res2);
    }
};
// @lc code=end

