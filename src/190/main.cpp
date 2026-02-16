/*
 * @Author: Dragon-qing
 * @Date: 2026-02-16 21:19:40
 * @LastEditors: Dragon-qing
 * @LastEditTime: 2026-02-16 21:36:03
 * @FilePath: \leetcode\src\190\main.cpp
 * @Description: 
 */
#include <iostream>

class Solution {
public:
    int reverseBits(int n) {
        n = (n << 16) | (n >> 16);
        n = ((n & 0x00ff00ff) << 8) | ((n & 0xff00ff00) >> 8);
        n = ((n & 0x0f0f0f0f) << 4) | ((n & 0xf0f0f0f0) >> 4);
        n = ((n & 0x33333333) << 2) | ((n & 0xcccccccc) >> 2);
        n = ((n & 0x55555555) << 1) | ((n & 0xaaaaaaaa) >> 1);

        return n;
    }
};

int main()
{
    Solution s;
    std::cout << s.reverseBits(43261596);
    return 0;
}