/*
 * @Author: dragon-qing
 * @Date: 2026-03-01
 * @LastEditors: dragon-qing
 * @FilePath: \leetcode\src\1523\solution.cpp
 * @Description: 数学
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countOdds(int low, int high) {
        int ans = 0;

        int diff = high - low - 1;
        if (diff % 2 == 0)
        {
            ans += diff / 2;
        }
        else
        {
            if (low % 2 == 0)
            {
                ans += (diff + 1) / 2;
            }
            else
            {
                ans += diff / 2;
            }
        }
        if (high % 2 != 0)
        {
            ans++;
        }
        if (low % 2 != 0)
        {
            if (low != high)
            {
                ans++;
            }
            
        }

        return ans;
    }
};


int main()
{
    Solution s;
    cout << s.countOdds(21, 22);
    return 0;
}