/*
 * @Author: Dragon-qing
 * @Date: 2026-04-08
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3653\solution.cpp
 * @Description: 区间乘法查询后的异或 I, 暴力
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3653 lang=cpp
 *
 * [3653] 区间乘法查询后的异或 I
 */

// @lc code=start
class Solution {
public:
    void DAC(vector<int>& nums, vector<vector<int>>& queries, int begin, int end)
    {
        if (begin == end) return;
        else if (begin + 1 == end)
        {
            for (int i = queries[begin][0]; i <= queries[begin][1]; i += queries[begin][2])
            {
                nums[i] = ((long long)nums[i] * queries[begin][3]) % MOD;
            }
            return;
        }
        int mid = (begin + end) / 2;
        DAC(nums, queries, begin, mid);
        DAC(nums, queries, mid, end);
    }
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        DAC(nums, queries, 0, queries.size());
        int res = nums.back();
        nums.pop_back();
        for (auto i : nums)
        {
            res ^= i;
        }
        return res;
    }
private:
    const int MOD = 1e9 + 7;
};
// @lc code=end

int main()
{
    vector<int> nums = {1,1,1};
    vector<vector<int>> quer = {
        {0,2,1,4}
    };
    Solution s;
    s.xorAfterQueries(nums, quer);
    return 0;
}
