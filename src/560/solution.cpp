/*
 * @Author: Dragon-qing
 * @Date: 2026-03-10
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\560\solution.cpp
 * @Description: 子串
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>hashmap{};
        int ans = 0;
        hashmap[0] = 1;
        int sum = 0;

        for (int i : nums)
        {
            sum += i;
            int target = sum - k;
            ans += hashmap[target];
            hashmap[sum] += 1;
        }
        return ans;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> v = {
        1
    };
    cout << s.subarraySum(v, 0);
}