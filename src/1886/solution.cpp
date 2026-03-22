#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1886 lang=cpp
 *
 * [1886] 判断矩阵经轮转后是否一致
 */

// @lc code=start
class Solution {
public:
    /**
     * @brief: 旋转后的坐标变换
     * @param {int} row 横坐标
     * @param {int} col 纵坐标
     * @param {int} n 正方形大小
     * @param {int} type 旋转类型：1，转一次；2，转两次；3，转三次；4, 转四次
     * @return {pair<int, int>} 返回变化后的坐标
     */
    pair<int, int> PosTransform(int row, int col, int n, int type)
    {
        int x = -1, y = -1;
        switch (type)
        {
        case 1 : 
            x = col;
            y = n - 1 - row;
            break;
        case 2:
            x = n - 1 - row;
            y = n - 1 - col;
            break;
        case 3:
            x = n - 1 - col;
            y = row;
            break;
        case 4:
            x = row;
            y = col;
        default: 
            break;
        }
        return {x, y};
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        vector<int> candidate = {1,2,3,4}; // 候选类型
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < n; c++)
            {
                auto tmpV = candidate;
                for (auto i : tmpV)
                {
                    auto[x, y] = PosTransform(r, c, n, i);
                    if (mat[r][c] != target[x][y])
                    {
                        erase(candidate, i);
                    }
                }
                if (candidate.empty())
                {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

