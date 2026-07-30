/*
 * @Author: Dragon-qing
 * @Date: 2026-07-30
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3014\solution.cpp
 * @Description: 贪心
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3014 lang=cpp
 *
 * [3014] 输入单词需要的最少按键次数 I
 */

// @lc code=start
class Solution {
public:
    int minimumPushes(string word) {
        vector<int> latters(26, 0);
        for (char c : word) {
            latters[c - 'a'] += 1;
        }

        ranges::sort(latters, std::greater());

        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans += latters[i] * (i / 8 + 1);
        }

        return ans;
    }
};
// @lc code=end

