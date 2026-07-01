/*
 * @Author: Dragon-qing
 * @Date: 2026-07-01
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\39\solution.cpp
 * @Description: 回溯
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ranges::sort(candidates);

        BackTracking(target, candidates, 0);
        return ans;
    }

    /**
     * @brief: 回溯
     * @param {int} diff: 差值（还需要多少）
     * @param {int} offset: 去重偏移量，eg：3,4与4,3是相同的，所以只取3,4即可。
     * 偏移量之前的数不在考虑，否则会有重复结果；
     * @return {*}
     */    
    void BackTracking(int diff, vector<int>& candidates, int offset)
    {
        if (diff == 0)
        {
            ans.push_back(tmp);
        }

        for (int i = offset; i < candidates.size(); i++) {
            int n = candidates[i];
            if (n > diff) { // 剪枝
                break;
            }

            tmp.push_back(n);
            BackTracking(diff - n, candidates, i);
            tmp.pop_back();
        }
    }
private:
    vector<vector<int>> ans;
    vector<int> tmp;

};
// @lc code=end

