/*
 * @Author: Dragon-qing
 * @Date: 2026-02-28
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\1680\main.cpp
 * @Description: 位运算,模拟
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int concatenatedBinary(int n) {
        int mod = 1e9 + 7;
        long long sum = 0;
        int length = 0;
        for (int i = 1; i <= n; i++)
        {
            if ((i & (i - 1)) == 0)
            {
                length += 1;
            }
            sum = ((sum << length) + i) % mod;
        }
        return sum;
    }
};

int main()
{
    Solution s;
    cout << s.concatenatedBinary(1) << endl;
    cout << s.concatenatedBinary(3) << endl;
    cout << s.concatenatedBinary(12) << endl;
    return 0;
}