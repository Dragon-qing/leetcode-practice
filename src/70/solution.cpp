/*
 * @Author: Dragon-qing
 * @Date: 2026-09-03
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\70\solution.cpp
 * @Description: 动态规划
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        int one_step = 2; // 最后一步
        int two_step = 1; // 最后距离两步
        if (n == 1) {
            return two_step;
        } else if (n == 2) {
            return one_step;
        }

        int ans = 0;
        for (int i = 3; i <= n; i++) {
            ans = one_step + two_step;
            two_step = one_step;
            one_step = ans;
        }

        return ans;
    }
};
// @lc code=end

