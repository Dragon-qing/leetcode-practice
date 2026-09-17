/*
 * @Author: Dragon-qing
 * @Date: 2026-09-17
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\1477\solution.cpp
 * @Description: 前缀和，动态规划
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1477 lang=cpp
 *
 * [1477] 找两个和为目标值且不重叠的子数组
 */

// @lc code=start
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int minL = n;
        int ans = n + 1;
        unordered_map<int, int> pos;
        pos[0] = -1; // 初始化为-1方便后续计算

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (pos.contains(sum - target)) {
                int j = pos[sum - target];
                int l = i - j;
                ans = min(ans, l + (j == -1 ? n : arr[j]));
                minL = min(l, minL);
            }
            arr[i] = minL;
            pos[sum] = i;
        }

        return ans == n + 1 ? -1 : ans;
    }
};
// @lc code=end

