/*
 * @Author: Dragon-qing
 * @Date: 2026-07-28
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3517\solution.cpp
 * @Description: 计数排序
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3517 lang=cpp
 *
 * [3517] 最小回文排列 I
 */

// @lc code=start
class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> counter(26, 0);

        // 计数排序前半段
        for (int i = 0; i < s.size() / 2; i++) {
            counter[s[i] - 'a'] += 1;
        }

        int left = 0;
        int right = s.size() - 1;
        for (int i = 0; i < 26; i++) {
            while (counter[i]) {
                s[left++] = 'a' + i;
                s[right--] = 'a' + i;
                counter[i]--;
            }
        }

        return s;
    }
};
// @lc code=end

