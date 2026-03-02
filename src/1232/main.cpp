/*
 * @Author: Dragon-qing
 * @Date: 2026-03-02
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\1232\main.cpp
 * @Description: 数学
 * @note: 平移所有点后，使用Ax+By=0来建立方程可以避免除法运算。
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x1 = coordinates[0][0];
        int y1 = coordinates[0][1];
        int x2 = coordinates[1][0];
        int y2 = coordinates[1][1];

        double k = 0;
        bool zeroFlag = false;
        if (x2 - x1 != 0)
        {
            k = (y2 - y1) * 1.0 / (x2 - x1);
        }
        else
        {
            zeroFlag = true;
        }
        double b = y1 - k * x1;

        for (int i = 2; i < (int)coordinates.size(); i++)
        {
            if (zeroFlag)
            {
                if (coordinates[0][0] != coordinates[i][0])
                {
                    return false;
                }
            }
            else
            {
                int tmpy = static_cast<int>(coordinates[i][0] * k + b);
                if (tmpy != coordinates[i][1])
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> vec = {
        {2,1},{4,2},{6,3}
    };
    cout << s.checkStraightLine(vec);

    return 0;
}