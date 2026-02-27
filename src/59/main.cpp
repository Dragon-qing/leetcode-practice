/*
 * @Author: dragon-qing
 * @Date: 2026-02-27
 * @LastEditors: dragon-qing
 * @FilePath: \leetcode\src\59\main.cpp
 * @Description: 过程模拟
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n, 0));
        int startx = 0, starty = 0;
        int i, j;
        int offset = 1;
        int loop = n / 2;
        int count = 1;

        while (loop)
        {
            i = startx;
            j = starty;

            for (;j < n - offset; j++)
            {
                res[i][j] = count++;
            }
            for (;i < n - offset; i++)
            {
                res[i][j] = count++;
            }
            for (;j > startx; j--)
            {
                res[i][j] = count++;
            }
            for (;i > startx; i--)
            {
                res[i][j] = count++;
            }
            loop--;
            startx++;
            starty++;
            offset++;
        }

        if (n % 2 != 0)
        {
            res[n / 2][n / 2] = count;
        }
        return res;
    }
};

int main()
{
    Solution s;
    int n = 5;
    vector<vector<int>> res = s.generateMatrix(n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}