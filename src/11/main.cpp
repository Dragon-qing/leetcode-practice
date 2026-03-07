/*
 * @Author: Dragon-qing
 * @Date: 2026-03-07
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\11\main.cpp
 * @Description: 双指针
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        while (left < right)
        {
            int area = (right - left) * min(height[right], height[left]);
            ans = max(area, ans);
            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
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
        1,8,6,2,5,4,8,3,7
    };
    cout << s.maxArea(v);
}