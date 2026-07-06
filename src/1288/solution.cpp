/*
 * @Author: Dragon-qing
 * @Date: 2026-07-06
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\1288\solution.cpp
 * @Description: 排序
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1288 lang=cpp
 *
 * [1288] 删除被覆盖区间
 */

// @lc code=start
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // 第一个值升序排序，第一个值相同时，按第二个值降序排序
        ranges::sort(intervals, {}, [](vector<int>& a){
            return pair<int, int>(a[0], -a[1]);
        });

        int maxRight = 0;
        int ans = 0;
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i][1] > maxRight) {
                maxRight = intervals[i][1];
                ans += 1;
            } 
        }

        return ans;
    }
};
// @lc code=end

