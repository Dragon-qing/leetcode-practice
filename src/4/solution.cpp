/*
 * @Author: Dragon-qing
 * @Date: 2026-04-11
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\4\solution.cpp
 * @Description: 寻找两个正序数组的中位数, 二分查找
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int left = (m + n + 1) / 2; // k从1开始
        int right = (m + n + 2) / 2;
        
        double a = GetKth(nums1, 0, m - 1, nums2, 0, n - 1, left);
        double b = GetKth(nums1, 0, m - 1, nums2, 0, n - 1, right);
        return (a + b) * 0.5;
    }

    double GetKth(vector<int> &nums1, int l1, int r1, vector<int> &nums2, int l2, int r2, int k)
    {
        if (r1 - l1 + 1 > r2 - l2 + 1) return GetKth(nums2, l2, r2, nums1, l1, r1, k);
        if (r1 - l1 + 1 == 0) return static_cast<double>(nums2[l2 + k - 1]);

        if (k == 1) return static_cast<double>(min(nums1[l1], nums2[l2]));

        int i = min(l1 + k / 2 - 1, r1);
        int j = min(l2 + k / 2 - 1, r2);

        if (nums1[i] < nums2[j])
        {
            return GetKth(nums1, i + 1, r1, nums2, l2, r2, k - (i - l1 + 1));
        }
        else
        {
            return GetKth(nums1, l1, r1, nums2, j + 1, r2, k - (j - l2 + 1));
        }
    }
};
// @lc code=end

int main()
{
    vector<int> v1 = {1,2};
    vector<int> v2 = {3,4};
    Solution s;
    cout << s.findMedianSortedArrays(v1, v2);
    return 0;
}
