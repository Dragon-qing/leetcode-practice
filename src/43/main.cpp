/*
 * @Author: Dragon-qing
 * @Date: 2026-03-02
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\43\main.cpp
 * @Description: 数学，大数乘法
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        vector<int> res(m+n, 0);
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = res[i + j + 1] + mul;
                res[i + j] += sum / 10;
                res[i + j + 1] = sum % 10;

            }
        }
        string ans = "";
        int i = 0;
        while (i < (int)res.size() && res[i] == 0)
        {
            i++;
        }
        while (i < (int)res.size())
        {
            ans.push_back(res[i] + '0');
            i++;
        }
        if (ans.empty())
        {
            ans = "0";
        }

        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.multiply("123", "456");
    return 0;
}