/*
 * @Author: Dragon-qing
 * @Date: 2026-03-01
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\976\main.cpp
 * @Description: 数学
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        std::ranges::sort(nums, [](int a, int b){return a > b;});
        int rangeMax = nums.size() - 2;
        int res = 0;
        for (int i = 0; i < rangeMax; i++)
        {
            int a = nums[i];
            int b = nums[i + 1];
            int c = nums[i + 2];
            if (a < b + c)
            {
                res = a + b + c;
                break;
            }
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {
        1,2,1,10
    };
    cout << s.largestPerimeter(nums);
}