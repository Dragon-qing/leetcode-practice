/*
 * @Author: Dragon-qing
 * @Date: 2026-07-18
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\1291\solution.cpp
 * @Description: 模拟
 */

#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1291 lang=cpp
 *
 * [1291] 顺次数
 */

// @lc code=start
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int minLength = to_string(low).size();
        int maxLength = to_string(high).size();

        vector<int> ans;
        for (int length = minLength; length <= maxLength; length++) {
            for (int begin = 0; begin <= 9 - length; begin++) {
                int tmp = stoi(digits.substr(begin, length));
                if (low <= tmp && tmp <= high) {
                    ans.push_back(tmp);
                }
            }
        }

        return ans;
    }

private:
    const string digits = "123456789";
};
// @lc code=end

