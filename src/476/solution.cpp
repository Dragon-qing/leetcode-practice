/*
 * @Author: Dragon-qing
 * @Date: 2026-03-11
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\476\solution.cpp
 * @Description: 位运算
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=476 lang=cpp
 *
 * [476] 数字的补数
 */

// @lc code=start
class Solution {
public:
    int findComplement(int num) {
        int cnt = bit_width((uint32_t)num);
        return pow(2, cnt) - 1 - num;
    }
};
// @lc code=end

