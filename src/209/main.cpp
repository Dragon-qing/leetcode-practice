/*
 * @Author: Dragon-qing
 * @Date: 2026-02-26
 * @LastEditors: Dragon-qing
 * @LastEditTime: 2026-02-26
 * @FilePath: \leetcode\src\209\main.cpp
 * @Description: 滑动窗口
 */
#include <iostream>
#include <vector>
using std::vector;


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLength = 0;
        int sum = 0;
        int result = INT32_MAX;
        int preIdx = 0;

        for (int lastIdx = 0; lastIdx < (int)nums.size(); lastIdx++)
        {
            sum += nums[lastIdx];
            while(sum >= target)
            {
                minLength = lastIdx - preIdx + 1;
                result = result > minLength ? minLength : result;
                sum -= nums[preIdx];
                preIdx += 1;
            }
        }

        return result < INT32_MAX ? result : 0;
    }
};

int main()
{
    Solution s;
    vector<int> nums {2,3,1,2,4,3};
    std::cout << s.minSubArrayLen(7, nums);
    return 0;
}