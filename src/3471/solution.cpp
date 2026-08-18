/*
 * @Author: Dragon-qing
 * @Date: 2026-08-18
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3471\solution.cpp
 * @Description: 模拟
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3471 lang=cpp
 *
 * [3471] 找出最大的几近缺失整数
 */

// @lc code=start
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        if (k == nums.size()) {
            return ranges::max(nums);
        }

        unordered_map<int, int> hash;
        int start = nums.front();
        int end = nums.back();

        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]] += 1;
        }

        int ans = -1;

        if (k == 1) {
            for (auto[x, y] : hash) {
                if (y == 1) {
                    ans = max(ans, x);
                }
            }
        } else {
            if (hash[start] != 1) start = -1;
            if (hash[end] != 1) end = -1;
            ans = max(start, end);
        }
        

        return ans;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> nums = {3,9,2,1,7};
    cout << s.largestInteger(nums, 3);
    return 0;
}
