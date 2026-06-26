/*
 * @Author: Dragon-qing
 * @Date: 2026-06-26
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\78\solution.cpp
 * @Description: 回溯
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        ans.push_back({});
        BackTracking(nums, 0);
        return ans;
    }
    
    void BackTracking(vector<int>& nums, int index) {
        ans.push_back(tmp);

        for (int i = index; i < nums.size(); i++)
        {
            tmp.push_back(nums[i]);
            BackTracking(nums, i + 1);
            tmp.pop_back();
        }
    }
private: 
    vector<vector<int>> ans;
    vector<int> tmp;
};
// @lc code=end

