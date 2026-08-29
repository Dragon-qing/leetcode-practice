/*
 * @Author: Dragon-qing
 * @Date: 2026-08-29
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\2948\solution.cpp
 * @Description: 排序，并查集
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=2948 lang=cpp
 *
 * [2948] 交换得到字典序最小的数组
 */

// @lc code=start
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> pos(n);

        ranges::iota(pos, 0);
        ranges::sort(pos, {}, [&](int i){
            return nums[i];
        });

        vector<int> ans(n);
        int start = 0;
        for (int i = 0; i < n; i++) {
            if (i == n - 1 || nums[pos[i + 1]] - nums[pos[i]] > limit) {
                vector<int> subPos(pos.begin() + start, pos.begin() + i + 1);
                ranges::sort(subPos);
                for (int j = 0; j < subPos.size(); j++) {
                    ans[subPos[j]] = nums[pos[start + j]];
                }
                start = i + 1;
            }
        }

        return ans;
    }
};
// @lc code=end

