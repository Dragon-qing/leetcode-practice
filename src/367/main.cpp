/*
 * @Author: Dragon-qing
 * @Date: 2026-02-24
 * @LastEditors: Dragon-qing
 * @LastEditTime: 2026-02-24
 * @FilePath: \leetcode\src\367\main.cpp
 * @Description: 二分法
 */
#include <iostream>

class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1;
        int right = num;
        int mid = 0;

        if (num == 1)
        {
            return true;
        }

        if (right > 46340) // 防止溢出
        {
            right = 46341;
        }

        while (left < right)
        {
            mid = (left + right) / 2;
            if (mid * mid > num)
            {
                right = mid;
            }
            else if (mid * mid < num)
            {
                left = mid + 1;
            }
            else 
            {
                return true;
            }
        }
        
        return false;
    }
};

int main()
{
    Solution s;
    std::cout << s.isPerfectSquare(1);
    return 0;
}