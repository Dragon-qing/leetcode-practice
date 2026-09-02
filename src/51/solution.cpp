/*
 * @Author: Dragon-qing
 * @Date: 2026-09-02
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\51\solution.cpp
 * @Description: 回溯
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        BackTracking(0, n);

        vector<vector<string>> res;

        for (auto &v : ans) {
            vector<string> t(n, string(n, '.'));
            for (auto &[x, y] : v) {
                t[x][y] = 'Q';
            }
            res.push_back(t);
        }

        return res;
    }

    void BackTracking(int row, int n)
    {
        if (row == n) {
            ans.emplace_back(cur);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (Check(row, i)) {
                cur.push_back({row, i});
                BackTracking(row + 1, n);
                cur.pop_back(); // 回退
            }
        }
    }
private:
    vector<pair<int, int>> cur;
    vector<vector<pair<int, int>>> ans;

    // 可以优化成O(1);
    // 使用三个数组分别记录列，正斜线(y - x)和反斜线(y + x),利用三个数组快速判断
    bool Check(int x, int y) 
    {
        for (auto& [r, c] : cur) {
            int dx = abs(x - r);
            int dy = abs(y - c);
            if (dx == 0 || dy == 0 || dx == dy) {
                return false; // 在皇后攻击范围内
            }
        }

        return true;
    }
};
// @lc code=end

int main()
{
    Solution s;
    s.solveNQueens(4);
    return 0;
}
