/*
 * @Author: Dragon-qing
 * @Date: 2026-03-03
 * @LastEditors: Dragon-qing
 * @FilePath: \leetcode\src\50\main.cpp
 * @Description: 递归，快速幂
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (fabs(x) - 1e-8 < 0 && n < 0)
        {
            return numeric_limits<double>::infinity();
        }
        if (n == 0)
        {
            return 1.0;
        }
        long long N = n;    //防止溢出
        if (N < 0)
        {
            x = 1 / x;
            N = -N;
        }
        return FastPow(x, N);
    }
private:
    /**
     * @brief: 快速幂
     * @param {double} x 底数
     * @param {long long} n 幂数
     * @return {double} 结果
     */
    double FastPow(double x, long long n)
    {
        if (n == 0)
        {
            return 1.0;
        }
        else if (n == 1)
        {
            return x;
        }
        double helf = FastPow(x, n / 2);
        if (n % 2 == 0)
        {
            return helf * helf;
        }
        return helf * helf * x;
    }
};

int main()
{
    Solution s;
    cout << s.myPow(2, 10);
    return 0;
}
