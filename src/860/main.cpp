/*
 * @Author: Dragon-qing
 * @Date: 2026-03-01
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\860\main.cpp
 * @Description: 数学，贪心算法
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int money5 = 0;
        int money10 = 0;
        for (int m: bills)
        {
            if (m == 5)
            {
                money5++;
            }
            else if (m == 10)
            {
                if (money5 == 0)
                {
                    return false;
                }
                else
                {
                    money5--;
                    money10++;
                }
            }
            else if (m == 20)
            {
                if (money10)
                {
                    money10--;
                    if (money5)
                    {
                        money5--;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    if (money5 >= 3)
                    {
                        money5 -= 3;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<int>b{5,5,10,10,20};
    cout << s.lemonadeChange(b);
}