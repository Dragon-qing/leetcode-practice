/*
 * @Author: Dragon-qing
 * @Date: 2026-03-06
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\128\main.cpp
 * @Description: 数组，哈希
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>hashset(nums.begin(), nums.end());

        int ans = 0;
        for (int i : hashset)
        {
            if (hashset.contains(i-1))
            {
                continue;
            }
            int idx = i + 1;
            while (hashset.contains(idx))
            {
                idx++;
            }
            ans = max(idx - i, ans);
            if (ans > nums.size() / 2)
            {
                break;
            }
        }

        return ans;
    }
};