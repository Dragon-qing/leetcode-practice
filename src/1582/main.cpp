/*
 * @Author: Dragon-qing
 * @Date: 2026-03-04
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\1582\main.cpp
 * @Description: 矩阵
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int *rowZero = new int[m]{};
        int *colZero = new int[n]{};
        stack<int> pos{};
        int ans = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int tmp = mat[i][j];
                if (tmp == 1)
                {
                    pos.push(i * n + j);
                }
                else if (tmp == 0)
                {
                    rowZero[i] += 1;
                    colZero[j] += 1;
                }
            }
        }

        while (!pos.empty())
        {
            int tmp = pos.top();
            int row = tmp / n;
            int col = tmp % n;

            if (rowZero[row] == n - 1 && colZero[col] == m - 1)
            {
                ans += 1;
            }
            pos.pop();
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> mat = {
        {1,0,0},{0,1,0},{0,0,1}
    };
    cout << s.numSpecial(mat);
    return 0;
}