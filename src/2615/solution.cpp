/*
 * @Author: Dragon-qing
 * @Date: 2026-04-23
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\2615\solution.cpp
 * @Description: 等值距离和, 哈希、前缀和
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=2615 lang=cpp
 *
 * [2615] 等值距离和
 */

// @lc code=start
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; ++i)
            groups[nums[i]].push_back(i); // 相同元素分到同一组，记录下标

        vector<long long> ans(n);
        long long s[n + 1];
        s[0] = 0;
        for (auto& [_, a]: groups) {
            int m = a.size();
            for (int i = 0; i < m; ++i)
                s[i + 1] = s[i] + a[i]; // 前缀和
            for (int i = 0; i < m; ++i) {
                long long target = a[i];
                long long left = target * i - s[i]; // 蓝色面积
                long long right = s[m] - s[i] - target * (m - i); // 绿色面积
                ans[target] = left + right;
            }
        }
        return ans;
    }
};
// @lc code=end

