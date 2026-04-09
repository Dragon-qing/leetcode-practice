/*
 * @Author: Dragon-qing
 * @Date: 2026-04-09
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\121\solution.cpp
 * @Description: 买卖股票的最佳时机，贪心
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        stack<int> maxSuffix;
        int n = prices.size();
        if (n == 1) return 0;

        int res = 0;

        maxSuffix.push(prices[n - 1]);
        for (int i = n - 3; i >= 0; i--)
        {
            maxSuffix.push(max(maxSuffix.top(), prices[i + 1]));
        }

        for (int i = 0; i < n - 1; i++)
        {
            res = max(res, maxSuffix.top() - prices[i]);
            maxSuffix.pop();
        }

        return res;
    }
};
// @lc code=end

int main()
{
    vector<int> v = {7,6,4,3,1};
    Solution s;
    s.maxProfit(v);
    return 0;
}

