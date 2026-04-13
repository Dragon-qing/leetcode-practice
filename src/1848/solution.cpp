/*
 * @Author: Dragon-qing
 * @Date: 2026-04-13
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\1848\solution.cpp
 * @Description: 到目标元素的最小距离，数组
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1848 lang=cpp
 *
 * [1848] 到目标元素的最小距离
 */

// @lc code=start
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int left = start, right = start + 1;
        int minDis = INT32_MAX;
        int n = nums.size();
        while (left >= 0)
        {
            if (nums[left] == target)
            {
                minDis = abs(start - left);
                break;
            } 
            left--;
        }

        while (right < n)
        {
            if (nums[right] == target)
            {
                minDis = min(minDis, abs(start - right));
                break;
            }
            right++;
        }

        return minDis;
    }
};
// @lc code=end

