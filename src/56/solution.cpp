/*
 * @Author: Dragon-qing
 * @Date: 2026-03-11
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\56\solution.cpp
 * @Description: 排序，数组
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int> &b)
    {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        ranges::sort(intervals, cmp);
        vector<vector<int>> res{};
        for (auto v : intervals)
        {
            if (!res.empty())
            {
                auto pre = res.back();
                if (v.back() >= pre.back() && v.front() <= pre.back())
                {
                    pre[1] = v[1];
                    res.pop_back();
                    res.push_back(pre);
                }
                else if (v.front() > pre.back())
                {
                    res.emplace_back(v);
                }

            }
            else
            {
                res.emplace_back(v);
            }
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<vector<int>> vector
    {
        {1,4},{2, 3}
    };
    s.merge(vector);
    return 0;
}
