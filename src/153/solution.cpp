/*
 * @Author: Dragon-qing
 * @Date: 2026-04-11
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\153\solution.cpp
 * @Description: 寻找旋转排序数组中的最小值，二分查找
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;

        if (n == 1 || nums[0] < nums[r]) return nums[0];

        while (l < r)
        {
            int m = (l + r) / 2;

            if (nums[r] > nums[m])
            {
                r = m; // 可能最小值就是m
            }
            else
            {
               l = m + 1;
            }
        }

        return nums[l];
    }
};
// @lc code=end

int main()
{
    vector<int> v = {7,0,1};
    Solution s;
    cout << s.findMin(v);
    return 0;
}
