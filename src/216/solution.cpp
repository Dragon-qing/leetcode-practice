/*
 * @Author: Dragon-qing
 * @Date: 2026-07-12
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\216\solution.cpp
 * @Description: 回溯
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        BackTracking(1, 0, k, n);
        return ans;
    }
private:
    vector<int> tmp;
    vector<vector<int>> ans;

    void BackTracking(int start, int sum, int k, int n) {
        if (sum > n) {
            return;
        }
        if (k == tmp.size()) {
            if (sum == n ) ans.push_back(tmp);
            return;
        }

        for (int i = start; i <= 9 - (k - tmp.size()) + 1; i++) {
            tmp.push_back(i);
            BackTracking(i + 1, sum + i, k, n);
            tmp.pop_back();
        }
    }
};
// @lc code=end

