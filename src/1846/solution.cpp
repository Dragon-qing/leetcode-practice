/*
 * @Author: Dragon-qing
 * @Date: 2026-06-29
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\1846\solution.cpp
 * @Description: 排序，贪心
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1846 lang=cpp
 *
 * [1846] 减小和重新排列数组后的最大元素
 */

// @lc code=start
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        ranges::sort(arr);
        int n = arr.size();
        arr[0] = 1;
        for (int i = 1; i < n; i++)
        {
            arr[i] = min(arr[i - 1] + 1, arr[i]);
        }
        return arr.back();
    }
};
// @lc code=end

