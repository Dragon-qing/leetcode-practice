/*
 * @Author: Dragon-qing
 * @Date: 2026-04-10
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\35\solution.cpp
 * @Description: 搜索插入位置，二分查找
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        int mid = 0;

        while (start <= end)
        {
            mid = (start + end) / 2;

            if (target == nums[mid]) return mid;

            if (target < nums[mid]) end = mid - 1;
            else start = mid + 1;
        }

        return start;
    }
};
// @lc code=end

int main()
{
    vector<int> v = {1,3,5,6};
    Solution s;
    s.searchInsert(v, 7);
    return 0;
}
