/*
 * @Author: Dragon-qing
 * @Date: 2026-09-05
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\40\solution.cpp
 * @Description: 回溯
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        used.resize(n, false);
        ranges::sort(candidates);
        BackTracking(candidates, target, 0);
        return ans;
    }

    void BackTracking(vector<int>& candidates, int target, int start)
    {
        if (target == 0) {
            ans.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size() && target - candidates[i] >= 0; i++) {
            if (i > 0 && used[i - 1] == false && candidates[i] == candidates[i - 1]) {
                continue;
            }
            path.push_back(candidates[i]);
            used[i] = true;
            BackTracking(candidates, target - candidates[i], i + 1);
            path.pop_back();
            used[i] = false;
        }
    }
private:
    vector<bool> used;
    vector<int> path;
    vector<vector<int>> ans;
};
// @lc code=end

