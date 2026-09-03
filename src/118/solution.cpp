/*
 * @Author: Dragon-qing
 * @Date: 2026-09-03
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\118\solution.cpp
 * @Description: 动态规划
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if (numRows == 1) {
            return ans;
        }

        for (int i = 2; i <= numRows; i++) {
            vector<int> curRow;
            vector<int> &prevRow = ans.back();
            curRow.emplace_back(1);
            for (int j = 1; j < i - 1; j++) {
                int left = prevRow[j - 1];
                int right = prevRow[j];
                curRow.emplace_back(left + right);
            }
            curRow.emplace_back(1);
            ans.emplace_back(curRow);
        }

        return ans;
    }
};
// @lc code=end

