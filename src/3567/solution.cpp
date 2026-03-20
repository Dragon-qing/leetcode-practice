/*
 * @Author: Dragon-qing
 * @Date: 2026-03-20
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3567\solution.cpp
 * @Description: 矩阵，模拟，暴力求解
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3567 lang=cpp
 *
 * [3567] 子矩阵的最小绝对差
 */

// @lc code=start
class Solution {
public:
    /**
     * @brief: 计算最小绝对差
     * @param {set<int>} &numSet
     * @return {int} 最小绝对差
     */
    int CalABSMin(set<int> &numSet)
    {
        if (numSet.size() <= 1)
        {
            return 0;
        }
        int dis = INT32_MAX;
        for (auto ptr = numSet.begin(); ptr != prev(numSet.end()); ptr++)
        {
            dis = min(abs(*(next(ptr)) - *ptr), dis);
        }
        return dis;
    }
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));
        set<int> numSet;
        unordered_map<int, int> numMap;
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                int tmp = grid[i][j];
                numMap[tmp] += 1;
                numSet.insert(tmp);
            }
        }
        ans[0][0] = CalABSMin(numSet);
        for (int r = 0; r < m - k + 1; r+= 2)
        {
            // 从左 -> 右
            for (int c = 0; c < n - k + 1; c++)
            {
                if (r == 0 && c == 0) // 跳过0,0位置
                {
                    continue;
                }
                for (int i = 0; i < k; i++)
                {
                    int add = 0;
                    int remove = 0;
                    if (c == 0) // 下移一格
                    {
                        remove = grid[r - 1][c + i];
                        add = grid[r + k - 1][c + i];
                    }
                    else // 右移
                    {
                        remove = grid[r + i][c - 1];
                        add = grid[r + i][c + k - 1];
                    }
                    numMap[remove] -= 1;
                    numMap[add] += 1;
                    if (numMap[remove] == 0)
                    {
                        numSet.erase(remove);
                    }
                    if (numMap[add] == 1)
                    {
                        numSet.insert(add);
                    }
                }
                ans[r][c] = CalABSMin(numSet);
            }
            // 从right -> left
            for (int c = n - k; c >= 0; c--)
            {
                if (r >= m - k) // r+1超过范围则跳过；
                {
                    break;
                }
                for (int i = 0; i < k; i++)
                {
                    int add = 0;
                    int remove = 0;
                    if (c == n - k) // 下移一格
                    {
                        remove = grid[r][c + i];
                        add = grid[r + k][c + i];
                    }
                    else // 左移
                    {
                        add = grid[r + i + 1][c];
                        remove = grid[r + i + 1][c + k];
                    }
                    numMap[remove] -= 1;
                    numMap[add] += 1;
                    if (numMap[remove] == 0)
                    {
                        numSet.erase(remove);
                    }
                    if (numMap[add] == 1)
                    {
                        numSet.insert(add);
                    }
                }
                ans[r + 1][c] = CalABSMin(numSet);
            }
        }
        return ans;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<vector<int>> v = 
    {
        {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}
    };
    s.minAbsDiff(v, 2);
    return 0;
}
