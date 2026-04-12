/*
 * @Author: Dragon-qing
 * @Date: 2026-04-12
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\1320\solution.cpp
 * @Description: 二指输入的的最小距离，动态规划，记忆化搜索
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1320 lang=cpp
 *
 * [1320] 二指输入的的最小距离
 */

// @lc code=start
class Solution
{
public:
    int minimumDistance(string word)
    {
        int n = word.size();
        vector<array<array<int, 26>, 26>> memo(n, {{}}); // 记忆数组

        for (auto &mat : memo)
        {
            for (auto &row : mat)
            {
                row.fill(-1); // 初始化为-1
            }
        }
        InitDis();
        int ans = INT32_MAX;
        for (int i : views::iota(0, 26))
        {
            ans = min(ans, dfs(n - 2, word[n - 1] - 'A', i, word, memo)); // i代表的是前缀，最后一个字符已经固定在finger1上，所以i填n-2
        }

        return ans;
    }

    /**
     * @brief: 深度优先遍历
     * @param {int} i: 已经输入多少个字母(前缀)
     * @param {int} finger1: 第一个手指所在字母位置
     * @param {int} finger2: 第二个手指所在位置
     * @param {string} s: 目标字符串
     * @param {vector<array<array<int, 26>, 26>>} &memo: 记忆数组
     * @return {int} 最小距离和
     */
    int dfs(int i, int finger1, int finger2, string s, vector<array<array<int, 26>, 26>> &memo)
    {
        if (i < 0) return 0;
        if (memo[i][finger1][finger2] != -1) return memo[i][finger1][finger2];

        int c = s[i] - 'A';

        int dis1 = dfs(i - 1, c, finger2, s, memo) + m_arrDis[c][finger1];
        int dis2 = dfs(i - 1, finger1, c, s, memo) + m_arrDis[c][finger2];

        int ans = min(dis1, dis2);
        memo[i][finger1][finger2] = ans;
        return ans;
    }

    /**
     * @brief: 初始化距离计算数组
     * @return {void}
     */
    void InitDis()
    {
        int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                x1 = i / 6;
                y1 = i % 6;
                x2 = j / 6;
                y2 = j % 6;

                m_arrDis[i][j] = abs(x1 - x2) + abs(y1 - y2);
            }
        }
    }

private:
    array<array<int, 26>, 26> m_arrDis; // 记录i，j两个字母之间的距离
};
// @lc code=end
