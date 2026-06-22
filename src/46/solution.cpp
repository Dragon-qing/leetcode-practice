/*
 * @Author: Dragon-qing
 * @Date: 2026-04-25
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\46\solution.cpp
 * @Description: 回溯
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        backTracking(nums);
        return ans;
    }

    void backTracking(vector<int>& nums)
    {
        if (m_vTemp.size() == nums.size()) {
            ans.push_back(m_vTemp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (m_hash.contains(nums[i])) {
                continue;
            }
            m_hash.insert(nums[i]);
            m_vTemp.push_back(nums[i]);
            backTracking(nums);
            m_hash.erase(nums[i]);
            m_vTemp.pop_back();
        }
    }
private:
    unordered_set<int> m_hash;
    vector<int> m_vTemp;
    vector<vector<int>> ans;
};
// @lc code=end

