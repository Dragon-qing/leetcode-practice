/*
 * @Author: Dragon-qing
 * @Date: 2026-09-19
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\416\solution.cpp
 * @Description: 动态规划
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int total = reduce(nums.begin(), nums.end());
        if (total % 2) {
            return false;
        }

        vector memo(n, vector<int>(total / 2 + 1, -1));

        auto dfs = [&](this auto &&dfs, int i, int j) -> bool {
            if (i < 0) {
                return j == 0;
            }
            int &res = memo[i][j];

            if (res != -1) {
                return res;
            }

            if (j < nums[i]) { // 不选
                return res = dfs(i - 1, j);
            }

            return res = dfs(i - 1, j) || dfs(i - 1, j - nums[i]);
        };

        return dfs(n - 1, total / 2);
    }
};
// @lc code=end

