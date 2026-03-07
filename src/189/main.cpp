/*
 * @Author: Dragon-qing
 * @Date: 2026-03-07
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\189\main.cpp
 * @Description: 数组
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.end() - k, nums.end());
        reverse(nums.begin(), nums.end() - k);
        reverse(nums.begin(), nums.end());
    }
};

int main()
{
    Solution s;
    vector<int> v{1,2,3,4,5,6,7};
    s.rotate(v, 3);
    for (int c : v)
    {
        cout << c << ' ';
    }
    return 0;
}