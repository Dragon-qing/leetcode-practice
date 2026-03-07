/*
 * @Author: Dragon-qing
 * @Date: 2026-03-07
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\42\main.cpp
 * @Description: 双指针
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxleft = 0, maxright = 0;
        int ans = 0;

        while (left < right)
        {
            maxleft = max(maxleft, height[left]);
            maxright = max(maxright, height[right]);
            if (height[left] <= height[right])
            {
                ans += maxleft - height[left];
                left++;
            }
            else
            {
                ans += maxright - height[right];
                right--;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v = {
        0,1,0,2,1,0,1,3,2,1,2,1
    };
    cout << s.trap(v);
    return 0;
}