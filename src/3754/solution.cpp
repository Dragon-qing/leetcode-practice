/*
 * @Author: Dragon-qing
 * @Date: 2026-07-07
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3754\solution.cpp
 * @Description: 模拟
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3754 lang=cpp
 *
 * [3754] 连接非零数字并乘以其数字和 I
 */

// @lc code=start
class Solution {
public:
    long long sumAndMultiply(int n) {
        if (n == 0) return 0;

        int sum = 0;
        int newNum = 0;
        int times = 1;
        while (n > 0) {
            int tmp = n % 10;
            n /= 10;
            if (tmp != 0) {
                sum += tmp;
                newNum += tmp * times;
                times *= 10;
            }
        }

        return newNum * (long long)sum;
    }
};
// @lc code=end

