/*
 * @Author: dragon-qing
 * @Date: 2026-03-04
 * @LastEditors: dragon-qing
 * @FilePath: \leetcode\src\349\main.cpp
 * @Description: 哈希表
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> ans{};
        unordered_set<int> hashSet{};

        for (int i : nums1)
        {
            hashSet.emplace(i);
        }
        for (int i : nums2)
        {
            if (hashSet.contains(i))
            {
                ans.emplace(i);
            }
        }

        return vector<int>(ans.begin(), ans.end());
    }
};

int main()
{
    Solution s;
    vector<int> v1 = {1, 2, 3, 5, 4, 4, 5, 10};
    vector<int> v2 = {1, 2, 3, 4, 4};
    auto res = s.intersection(v1, v2);
    for (auto i : res)
    {
        cout << i << ' ';
    }

    return 0;
}