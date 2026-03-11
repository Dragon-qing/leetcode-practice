/*
 * @Author: Dragon-qing
 * @Date: 2026-03-11
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\1009\solution.cpp
 * @Description: 二进制
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1009 lang=cpp
 *
 * [1009] 十进制整数的反码
 */

// @lc code=start
class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0)
        {
            return 1;
        }
        int i = n;
        int bits = 0;
        while(i != 0)
        {
            i = i >> 1;
            bits += 1;
        }
        return pow(2, bits) - 1 - n;
    }
};
// @lc code=end

int main()
{
    Solution s;
    cout << s.bitwiseComplement(5);
    return 0;
}