/*
 * @Author: Dragon-qing
 * @Date: 2026-02-28
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\1572\main.cpp
 * @Description: 矩阵
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;
        
        for (int left = 0, right = n - 1; left < n && right >= 0; left++, right--)
        {
            sum += mat[left][left] + mat[left][right];
        }

        if (n % 2 != 0)
        {
            int mid = n / 2;
            sum -= mat[mid][mid];
        }

        return sum;
    }
};

int main()
{
    vector<vector<int>> mat = {
        {1,2,3},{4,5,6},{7,8,9}
    };
    Solution s;
    cout << s.diagonalSum(mat);
    
    return 0;
}