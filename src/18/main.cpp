/*
 * @Author: dragon-qing
 * @Date: 2026-03-06
 * @LastEditors: dragon-qing
 * @FilePath: \leetcode\src\18\main.cpp
 * @Description: 双指针
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans{};
        int n = nums.size();
        int left = 0, right = n - 1;
        ranges::sort(nums);
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > target && nums[i] >= 0)
            {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] + nums[i] > target && nums[j] >= 0)
                {
                    break;
                }
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }
                left = j + 1;
                right = n - 1;
                while (left < right)
                {
                    if ((long)nums[i] + nums[j] + nums[left] + nums[right] < target)
                    {
                        left++;
                    }
                    else if ((long)nums[i] + nums[j] + nums[left] + nums[right] > target)
                    {
                        right--;
                    }
                    else
                    {
                        ans.emplace_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left + 1] == nums[left]){ left++; }
                        while (left < right && nums[right - 1] == nums[right]){ right--; }
                        left++;
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;

    return 0;
}