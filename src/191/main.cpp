/*
 * @Author: Dragon-qing
 * @Date: 2026-02-17
 * @LastEditors: Dragon-qing
 * @LastEditTime: 2026-02-17
 * @FilePath: \leetcode\src\191\main.cpp
 * @Description: 
 */
#include <iostream>

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while(n)
        {
            n &= (n-1);
            count++;
        }
        return count;
    }
};

int main()
{
    Solution s;
    std::cout << s.hammingWeight(3);
    return 0;
}