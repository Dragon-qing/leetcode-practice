/*
 * @Author: Dragon-qing
 * @Date: 2026-07-18
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\1979\solution.cpp
 * @Description: 数学
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1979 lang=cpp
 *
 * [1979] 找出数组的最大公约数
 */

// @lc code=start
class Solution {
public:
    int findGCD(vector<int>& nums) {
        auto [mn, mx] = ranges::minmax(nums);
        return gcd(mx, mn);
    }

private:
    int gcd(int a, int b)
    {
        // 辗转相除法
        int t = -1;
        while (t != 0) {
            t = a % b;
            a = b;
            b = t;
        }

        return a;
    }
};
// @lc code=end

