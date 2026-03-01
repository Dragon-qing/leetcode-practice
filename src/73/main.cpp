/*
 * @Author: Dragon-qing
 * @Date: 2026-02-28
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\73\main.cpp
 * @Description: 矩阵哈希表
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool rowflag = false;   // 第一行置0标志，最后置0，防止判断错误
        bool colflag = false;   // 第一列置0标志，最后置0，防止判断错误
        if (matrix[0][0] == 0)
        {
            rowflag = true;
            colflag = true;
        }

        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (matrix[row][col] == 0)  // 借用第一行和第一列来充当哈希表记录是否置0
                {
                    matrix[row][0] = 0;
                    matrix[0][col] = 0;
                    if (row == 0)
                    {
                        rowflag = true;
                    }
                    if (col == 0)
                    {
                        colflag = true;
                    }
                }
            }
        }

        for (int row = 1; row < m; row++)
        {
            if (!matrix[row][0])
            {
                for (int col = 0; col < n; col++)
                {
                    matrix[row][col] = 0;
                }
            }
        }

        for (int col = 1; col < n; col++)
        {
            if(!matrix[0][col])
            {
                for (int row = 0; row < m; row++)
                {
                    matrix[row][col] = 0;
                }
            }
        }
        if (rowflag)
        {
            for (int i = 0; i < n; i++)
            {
                matrix[0][i] = 0;
            }
        }
        if (colflag)
        {
            for (int i = 0; i < m; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};

int main()
{
    vector<vector<int>> matrix = {
        {1,2,3,4},{5,0,7,8},{0,10,11,12},{13,14,15,0}
    };
    Solution s;
    s.setZeroes(matrix);
    for (int i = 0; i < (int)matrix.size(); i++)
    {
        for(int j = 0; j < (int)matrix[0].size(); j++)
        {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}