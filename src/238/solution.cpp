/*
 * @Author: Dragon-qing
 * @Date: 2026-03-11
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\238\solution.cpp
 * @Description: 前缀和，数组
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除了自身以外数组的乘积
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sumL = 1;
        int sumR = 1;
        vector<int> ans(nums.size(), 1);
        for (int i = 0; i < (int)nums.size(); i++)
        {
            int rIdx = nums.size() - i - 1;
            if (i != 0)
            {
                sumL *= nums[i - 1];
                sumR *= nums[rIdx + 1];
            }
            ans[i] *= sumL;
            ans[rIdx] *= sumR;
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;

    Solution s;
    vector<int> vec = {
        1, 2, 3, 4
    };
    auto v = s.productExceptSelf(vec);
    return 0;
}
