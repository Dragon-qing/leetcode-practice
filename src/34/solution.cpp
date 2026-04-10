/*
 * @Author: Dragon-qing
 * @Date: 2026-04-10
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\34\solution.cpp
 * @Description: 在排序数组中查找元素的第一个和最后一个位置，二分查找
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1, mid = 0;
        if (n == 0)
        {
            return {-1, -1};
        }

        while (left <= right)
        {
            mid = (left + right) / 2;

            if (nums[mid] == target)
            {
                break;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else 
            {
                right = mid - 1;
            }
        }
        if (left > right)
        {
            return {-1, -1};
        }

        int start = mid, end = mid;
        while (start - 1 >= 0 && nums[start - 1] == target) start--;
        while (end +  1 < n && nums[end + 1] == target) end++;

        return {start, end};
    }
};
// @lc code=end

