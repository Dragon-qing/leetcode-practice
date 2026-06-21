/*
 * @Author: Dragon-qing
 * @Date: 2026-06-21
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\1833\solution.cpp
 * @Description: 计数排序
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1833 lang=cpp
 *
 * [1833] 雪糕的最大数量
 */

// @lc code=start
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int> cntArr(1e5 + 1, 0);
        int maxCost = 0;
        long long money = coins;
        for (int cost : costs) {
            cntArr[cost] += 1;
            maxCost = max(maxCost, cost);
        }

        int ans = 0;
        long long tmp = 0;
        for (int i = 1; i <= maxCost; i++) {
            if (cntArr[i] == 0) continue;
            tmp = static_cast<long long>(i) * cntArr[i];
            if (tmp > money) {
                ans += money / i;
                break;
            } else {
                money -= i * cntArr[i];
                ans += cntArr[i];
            }
        }

        return ans;
    }
};
// @lc code=end

