#include <bits/stdc++.h>
using namespace std;

/*
 * @Author: Dragon-qing
 * @Date: 2026-04-19
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\1855\solution.cpp
 * @Description: 下标对中的最大距离,双指针，二分查找
 */
/*
 * @lc app=leetcode.cn id=1855 lang=cpp
 *
 * [1855] 下标对中的最大距离
 */

// @lc code=start
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int res = 0;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] <= nums2[j]) {
                res = max(res, j - i);
                j++;
            } else {
                i++;
            }
        }

        return res;
    }
};
// @lc code=end

int main()
{
    vector<int> v1 = {2,2,2};
    vector<int> v2 = {10,10,1};
    Solution s;
    s.maxDistance(v1, v2);
    return 0;
}
