/*
 * @Author: Dragon-qing
 * @Date: 2026-03-07
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\1888\main.cpp
 * @Description: 滑动窗口
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlips(string s) {
        string target = "01";
        int n = s.size();

        int step = 0;
        for (int i = 0; i < n; i++)
        {
            if (target[i%2] != s[i])
            {
                step += 1;
            }
        }
        int ans = min(step, n - step);
        for (int i = 0; i < n; i++)
        {
            if (s[i] != target[i % 2])
            {
                step -= 1;
            }
            if (s[i] != target[(i + n) % 2])
            {
                step += 1;
            }
            ans = min({ans, step, n - step});
        }

        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.minFlips("111000");
    return 0;
}