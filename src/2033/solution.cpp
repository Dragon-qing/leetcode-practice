/*
 * @Author: Dragon-qing
 * @Date: 2026-04-28
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\2033\solution.cpp
 * @Description: 获取单值网格的最小操作数, 排序
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=2033 lang=cpp
 *
 * [2033] 获取单值网格的最小操作数
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();

        bool tmp = Sort(grid, x);
        if (!tmp) {return -1;}
        int mid = (m * n) / 2;
        int target = grid[mid / n][mid % n];
        int step = 0;
        for (auto& rows : grid)
        {
            for (auto& col : rows)
            {
                step += (abs(target - col) / x);
            }
        }

        return step;
    }

    bool Sort(vector<vector<int>>& v, int x)
    {
        vector<int> tmp;
        int remind = v[0][0] % x;

        // 1. 展平
        for (auto& row : v) {
            tmp.insert(tmp.end(), row.begin(), row.end());
        }

        // 2. 排序
        sort(tmp.begin(), tmp.end());

        // 3. 重组
        int k = 0;
        for (auto& row : v) {
            for (auto& item : row) {
                item = tmp[k++];
                if (item % x != remind) return false;
            }
        }
        return true;
    }
};
// @lc code=end

int main()
{
    vector<vector<int>> v = {
        {1,5},{2,3}
    };
    Solution s;
    cout << s.minOperations(v, 1);
    return 0;
}

