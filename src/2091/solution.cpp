/*
 * @Author: Dragon-qing
 * @Date: 2026-08-30
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\2091\solution.cpp
 * @Description: 贪心
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=2091 lang=cpp
 *
 * [2091] 从数组中移除最大值和最小值
 */

// @lc code=start
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;

        auto [minItr, maxItr] = ranges::minmax_element(nums);

        int l = min(minItr - nums.begin(), maxItr - nums.begin());
        int r = max(minItr - nums.begin(), maxItr - nums.begin());
        

        return min({n - l, r + 1, l + 1 + n - r});
    }
};
// @lc code=end

int main()
{
    vector<int> nums = {
        -1,-53,93,-42,37,94,97,82,46,42,-99,56,-76,-66,-67,-13,10,66,85,-28
    };
    Solution s;
    cout << s.minimumDeletions(nums);
    return 0;
}
