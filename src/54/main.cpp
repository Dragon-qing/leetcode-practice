/*
 * @Author: Dragon-qing
 * @Date: 2026-02-28
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\54\main.cpp
 * @Description: 矩阵,模拟
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int startx = 0, starty = 0;
        int i, j;
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();
        int offset = 1;
        int loop = min(m, n) / 2;
        vector<int>res{};

        while(loop--)
        {
            i = startx;
            j = starty;
            for (; j < n - offset; j++)
            {
                res.push_back(matrix[i][j]);
            }
            for (; i < m - offset; i++)
            {
                res.push_back(matrix[i][j]);
            }
            for (; j > starty; j--)
            {
                res.push_back(matrix[i][j]);
            }
            for (; i > startx; i--)
            {
                res.push_back(matrix[i][j]);
            }
            startx++;
            starty++;
            offset++;
        }

        if (min(m, n) % 2 != 0)
        {
            int mid = min(m, n) / 2;
            int range = max(m, n) - mid;
            for (int idx = mid; idx < range; idx++)
            {
                if (m > n)
                {
                    res.push_back(matrix[idx][mid]);
                }
                else
                {
                    res.push_back(matrix[mid][idx]);
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> v = {
    {2,5},{8,4},{0,-1}
    };
    auto vec = s.spiralOrder(v);
    for (auto i: vec)
    {
        cout << i << ' ';
    }
    return 0;
}