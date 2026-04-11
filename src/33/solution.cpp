/*
 * @Author: Dragon-qing
 * @Date: 2026-04-11
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\33\solution.cpp
 * @Description: 搜索旋转排序数组, 二分查找
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int rotatePos = n - 1;
        int preValue = nums[0];
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < preValue)
            {
                rotatePos = i - 1;
                break;
            }
            preValue = nums[i];
        }

        // 二分查找
        int start = rotatePos + 1, end = rotatePos + n;
        int mid = 0;

        while (start <= end)
        {
            mid = (start + end) / 2;
            if (nums[mid % n] == target)
            {
                return mid % n;
            }
            else if (nums[mid % n] < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return -1;
    }
};
// @lc code=end

int main()
{
    vector<int> v = {1};
    Solution s;
    cout << s.search(v, 1);
    return 0;
}
