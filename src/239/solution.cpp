/*
 * @Author: Dragon-qing
 * @Date: 2026-03-10
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\239\solution.cpp
 * @Description: 子串
 * @note：可以尝试用优先队列或单调队列来实现，比下面的方法更快。
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans{};
        int maxValue = INT32_MIN;
        maxValue = *max_element(nums.begin(), nums.begin() + k);
        unordered_map<int, int> hashmap{};
        for (int i = 0; i < k; i++)
        {
            hashmap[nums[i]]++;
            maxValue = max(maxValue, nums[i]);
        }
        ans.push_back(maxValue);
        for (int i = k; i < (int)nums.size(); i++)
        {
            int plus = nums[i];
            int sub = nums[i - k];
            hashmap[sub]--;
            if (hashmap[sub] == 0 && maxValue == sub && maxValue > plus)
            {
                // 重新计算maxvalue
                maxValue = *max_element(nums.begin() + i - k + 1, nums.begin() + i + 1);
            }
            else if (maxValue <= plus)
            {
                maxValue = plus;
            }
            hashmap[plus]++;
            ans.push_back(maxValue);
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v = {
        1,3,-1,-3,5,3,6,7
    };
    auto res = s.maxSlidingWindow(v, 3);
    for (auto i : res)
    {
        cout << i << ' ';
    }
    return 0;
}
