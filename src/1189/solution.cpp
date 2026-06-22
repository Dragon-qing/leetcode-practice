/*
 * @Author: Dragon-qing
 * @Date: 2026-06-22
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\1189\solution.cpp
 * @Description: 哈希表，计数
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1189 lang=cpp
 *
 * [1189] “气球” 的最大数量
 */

// @lc code=start
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        array<int, 26> hash{};
        int numOfa = 1;
        int numOfb = 1;
        int numOfl = 2;
        int numOfo = 2;
        int numOfn = 1;

        for (char c : text) {
            hash[c - 'a'] += 1;
        }

        int ans = 0;
        ans = min({hash['a' - 'a'] / numOfa, hash['b' - 'a'] / numOfb,
            hash['l' - 'a'] / numOfl, hash['o' - 'a'] / numOfo, hash['n' - 'a'] / numOfn});

        return ans;
    }
};
// @lc code=end

