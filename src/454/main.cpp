/*
 * @Author: Dragon-qing
 * @Date: 2026-03-05
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\454\main.cpp
 * @Description: 哈希表
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int>sumMap{};
        int n = nums1.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                sumMap[nums1[i] + nums2[j]] += 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int sum = -(nums3[i] + nums4[j]);
                if (sumMap.contains(sum))
                {
                    ans += sumMap[sum];
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {-2,-1};
    vector<int> nums3 = {-1,2};
    vector<int> nums4 = {0,2};
    cout << s.fourSumCount(nums1, nums2, nums3, nums4);
    return 0;
}