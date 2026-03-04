/*
 * @Author: dragon-qing
 * @Date: 2026-03-04
 * @LastEditors: dragon-qing
 * @FilePath: \leetcode\src\1\main.cpp
 * @Description: 哈希表
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        int idx = 0;
        for (int i : nums)
        {
            int gap = target - i;
            auto itr = numMap.find(gap);
            if (itr != numMap.end())
            {
                return {idx, itr->second};
            }
            numMap[i] = idx;
            idx++;
        }

        return {};
    }
};

int main()
{

    return 0;
}