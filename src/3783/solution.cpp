/*
 * @Author: Dragon-qing
 * @Date: 2026-04-18
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3783\solution.cpp
 * @Description: 整数的镜像距离, 模拟
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3783 lang=cpp
 *
 * [3783] 整数的镜像距离
 */

// @lc code=start
class Solution {
public:
    int mirrorDistance(int n) {
        std::function<int(int)> reverseFunc = [](int n) -> int{
            int res = 0;
            while (n > 0)
            {
                res *= 10;
                res += n % 10;
                n /= 10;
            }
            return res;
        };

        return abs(n - reverseFunc(n));
    }
};
// @lc code=end

