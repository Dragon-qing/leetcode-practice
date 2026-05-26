/*
 * @Author: Dragon-qing
 * @Date: 2026-05-26
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\77\solution.cpp
 * @Description: 回朔
 */
#include <bits/stdc++.h>
#include "fmt/base.h"
#include "fmt/ranges.h"
using namespace std;

/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    void BackTracking(int startidx, int n, int k)
    {
        if ((int)cur.size() == k)
        {
            res.push_back(cur);
            return;
        }

        for (int i = startidx; i <= n - (k - (int)cur.size()) + 1; i++)
        {
            cur.push_back(i);
            BackTracking(i + 1, n, k);
            cur.pop_back(); // 回溯
        }
    }
    vector<vector<int>> combine(int n, int k) {
        BackTracking(1, n, k);
        return res;
    }
private:
    vector<int> cur;
    vector<vector<int>> res;
};

int main()
{
    Solution s;
    auto res = s.combine(4, 4);
    for (auto v : res) {
        fmt::println("{}", v);
    }
    return 0;
}

// @lc code=end

