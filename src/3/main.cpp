/*
 * @Author: Dragon-qing
 * @Date: 2026-03-07
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\3\main.cpp
 * @Description: 滑动窗口
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
        {
            return 0;
        }
        int left = 0, right = 0;
        int ans = 0;
        int n = s.size();
        unordered_set<char> hashset{};
        while (right < n)
        {
            if (hashset.contains(s[right]))
            {
                ans = max(ans, right - left);
                hashset.erase(s[left]);
                left++;
            }
            else
            {
                hashset.emplace(s[right]);
                right++;
            }
        }
        ans = max(ans, right - left);
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.lengthOfLongestSubstring("dvdf");
    return 0;
}