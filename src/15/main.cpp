/*
 * @Author: Dragon-qing
 * @Date: 2026-03-05
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\15\main.cpp
 * @Description: 哈希表
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        vector<vector<int>> ans{};
        sort(nums.begin(), nums.end());

        
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)// 排序后第一个元素大于0，则不可能有符合条件的三元组
            {
                return ans;
            }
            if (i > 0 && nums[i] == nums[i - 1]) 
            {
                continue;
            }
            left = i + 1;
            right = n - 1;
            while (left < right)
            {
                if (nums[i] == -(nums[left] + nums[right]))
                {
                    ans.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while (left < right && nums[left + 1] == nums[left]){ left++; }
                    while (left < right && nums[right - 1] == nums[right]){ right--; }
                    left++;
                    right--;
                }
                else if (nums[i] < -(nums[left] + nums[right]))
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> vec = {
        0,0,0
    };
    
    auto res = s.threeSum(vec);
    for (auto v : res)
    {
        for (auto i : v)
        {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}